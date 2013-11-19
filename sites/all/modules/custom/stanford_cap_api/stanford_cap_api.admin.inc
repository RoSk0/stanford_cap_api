<?php
/**
 * @file
 * Administrative pages for Stanford CAP API module.
 */

/**
 * Form builder for details page.
 */
function stanford_cap_api_details_form($form, &$form_state) {
  $form['#attached']['css'][] = drupal_get_path('module', 'stanford_cap_api') . '/css/stanford_cap_api.css';

  // Checkboxes, used to display status and icons.
  $checkbox = '<div class="cap_checkbox cap_cannot_connect"><span></span></div>';

  // Status message.
  $status = stanford_cap_api_auth_status();
  $status_message = t("Currently, your site can't connect to CAP.");
  $status_message .= t('<br><em class="cap_additional">Please check your settings on the ') . l('settings page', 'admin/config/cap/settings') . '.</em>';
  if ($status) {
    $checkbox = '<div class="cap_checkbox cap_can_connect"><span></span></div>';
    $status_message = t('Currently, your site can connect to CAP.');
  }

  $form['status_wrapper'] = array(
    '#type' => 'container',
    '#prefix' => '<div class="cap_info_wrapper">',
    '#suffix' => '<div class="clearfix"></div></div>',
  );
  $form['status_wrapper']['status'] = array(
    '#markup' => $checkbox . $status_message,
  );

  return $form;
}

/**
 * Form builder for settings page.
 */
function stanford_cap_api_settings_form($form, &$form_state) {

  drupal_set_title(t('CAP API settings'));

  $form['connection'] = array(
    '#type' => 'fieldset',
    '#title' => t('Connection information'),
  );

  $form['connection']['description_wrapper'] = array(
    '#type' => 'container',
  );
  $form['connection']['description_wrapper']['description'] = array(
    '#markup' => t('Please enter the information you use to connect to the CAP API. This will be used for each callback to the CAP API itself.'),
  );

  $form['connection']['cap_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username:'),
    '#default_value' => variable_get('cap_username', ''),
    '#required' => TRUE,
  );

  $form['connection']['cap_password'] = array(
    '#type' => 'password',
    '#title' => t('Password:'),
  );

  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Advanced setting for CAP API and authentication URIs'),
  );

  $form['advanced']['cap_api_base_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Endpoint'),
    '#description' => t('CAP API endpoint URI, only useful when switching between development/production environment.'),
    '#default_value' => variable_get('cap_api_base_url', 'https://irt-dev.stanford.edu/cap-api'),
    '#required' => TRUE,
  );

  $form['advanced']['cap_auth_uri'] = array(
    '#type' => 'textfield',
    '#title' => t('Authentication URI'),
    '#description' => t('CAP API authentication URL.'),
    '#default_value' => variable_get('cap_auth_uri', 'https://authz-test.stanford.edu/oauth/token'),
    '#required' => TRUE,
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );

  return $form;
}

/**
 * Validation handler for settings form.
 */
function stanford_cap_api_settings_form_validate($form, &$form_state) {
  if (!empty($form_state['values']['cap_username']) && !empty($form_state['values']['cap_password'])) {
    $username = $form_state['values']['cap_username'];
    $password = $form_state['values']['cap_password'];
    $auth_uri = $form_state['values']['cap_auth_uri'];
    $auth_token = stanford_cap_api_auth($username, $password, $auth_uri);
    if (!$auth_token) {
      form_set_error('cap_username', t("Error. Can't connect to Stanford CAP API. Please check your username and password."));
      form_set_error('cap_password');
    }
  }
}

/**
 * Submit handler for settings form.
 */
function stanford_cap_api_settings_form_submit($form, &$form_state) {
  $config_vars = array(
    'cap_username',
    'cap_password',
    'cap_api_base_url',
    'cap_auth_uri',
  );
  $values = $form_state['values'];
  foreach ($config_vars as $config_var) {
    if (!empty($values[$config_var])) {
      variable_set($config_var, $values[$config_var]);
    }
  }
  drupal_set_message(t('Configuration saved.'));
}

/**
 * Checks that we can connect to CAP API.
 */
function stanford_cap_api_auth_status() {
  if (stanford_cap_api_request('/api/profiles/v1')) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}
