<?php

/**
 * @file
 * Main file.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function stanford_cap_api_profile_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = st('Stanford CAP API');
}

/**
 * Implements hook_install_tasks().
 */
function stanford_cap_api_profile_install_tasks() {
  $task['stanford_cap_api_credentials'] = array(
    'display_name' => st('Stanford CAP API credentials'),
    'display' => TRUE,
    'type' => 'form',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    'function' => 'stanford_cap_api_credentials_form',
  );

  return $task;
}

/**
 * CAP API credentials form builder.
 */
function stanford_cap_api_credentials_form($form, &$form_state) {

  drupal_set_title(st('Stanford CAP API access credentials'));

  $form['auth'] = array(
    '#type' => 'fieldset',
    '#title' => st('Authorization'),
  );

  $form['auth']['description_wrapper'] = array(
    '#type' => 'container',
  );
  $form['auth']['description_wrapper']['description'] = array(
    '#markup' => st('Please enter your authentication information for the CAP API.'),
  );

  $form['auth']['stanford_cap_api_username'] = array(
    '#type' => 'textfield',
    '#title' => st('Client ID:'),
    '#default_value' => 'go-global',
    '#required' => TRUE,
  );

  $form['auth']['stanford_cap_api_password'] = array(
    '#type' => 'password',
    '#title' => st('Authz secret:'),
  );

  $form['auth']['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => st('Advanced'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => st('Advanced setting for CAP API and authentication URIs'),
  );

  $form['auth']['advanced']['stanford_cap_api_base_url'] = array(
    '#type' => 'textfield',
    '#title' => st('Endpoint'),
    '#description' => st('CAP API endpoint URI, only useful when switching between development/production environment.'),
    '#default_value' => 'https://api.stanford.edu',
    '#required' => TRUE,
  );

  $form['auth']['advanced']['stanford_cap_api_auth_uri'] = array(
    '#type' => 'textfield',
    '#title' => st('Authentication URI'),
    '#description' => st('CAP API authentication URI.'),
    '#default_value' => 'https://authz.stanford.edu/oauth/token',
    '#required' => TRUE,
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Save settings'),
  );

  return $form;
}

/**
 * Validation handler for CAP API credentials form.
 */
function stanford_cap_api_credentials_form_validate($form, &$form_state) {
  if (!empty($form_state['values']['stanford_cap_api_username']) && !empty($form_state['values']['stanford_cap_api_password'])) {
    $username = $form_state['values']['stanford_cap_api_username'];
    $password = $form_state['values']['stanford_cap_api_password'];
    $auth_uri = $form_state['values']['stanford_cap_api_auth_uri'];
    $auth_token = stanford_cap_api_auth($username, $password, $auth_uri);
    if (!$auth_token) {
      form_set_error('stanford_cap_api_username', st("Error. Can't connect to Stanford CAP API. Please check your username and password."));
      form_set_error('stanford_cap_api_password');
    }
  }
}

/**
 * Submit handler for settings form.
 */
function stanford_cap_api_credentials_form_submit($form, &$form_state) {
  $config_vars = array(
    'stanford_cap_api_username',
    'stanford_cap_api_password',
    'stanford_cap_api_base_url',
    'stanford_cap_api_auth_uri',
  );
  $values = $form_state['values'];
  foreach ($config_vars as $config_var) {
    if (!empty($values[$config_var])) {
      variable_set($config_var, $values[$config_var]);
    }
  }
  drupal_set_message(st('Configuration saved.'));
}
