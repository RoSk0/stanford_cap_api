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

  $form['connection'] = array(
    '#type' => 'fieldset',
    '#title' => st('Connection information'),
  );

  $form['connection']['description_wrapper'] = array(
    '#type' => 'container',
  );
  $description = 'Please enter the information you use to connect to the'
    . ' CAP API. This will be used for each callback to the CAP API itself.'
    . ' Default user name is %user, default password is %pass.';
  $form['connection']['description_wrapper']['description'] = array(
    '#markup' => st($description, array(
      '%user' => 'go-global',
      '%pass' => 'testsecret',
    )),
  );

  $form['connection']['cap_username'] = array(
    '#type' => 'textfield',
    '#title' => st('Username:'),
    '#default_value' => variable_get('cap_username', 'go-global'),
  );

  $form['connection']['cap_password'] = array(
    '#type' => 'password',
    '#title' => st('Password:'),
    '#attributes' => array('value' => 'testsecret'),
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
  if (!empty($form_state['values']['cap_username']) && !empty($form_state['values']['cap_password'])) {
    $auth_token = stanford_cap_api_auth($form_state['values']['cap_username'], $form_state['values']['cap_password']);
    if (!$auth_token) {
      $msg = "Error. Can't connect to Stanford CAP API."
        . " Please check your username and password.";
      form_set_error('cap_username', st($msg));
      form_set_error('cap_password');
    }
    else {
      variable_set('cap_access_token', $auth_token);
      variable_set('cap_username', $form_state['values']['cap_username']);
      variable_set('cap_password', $form_state['values']['cap_password']);
    }
  }
}
