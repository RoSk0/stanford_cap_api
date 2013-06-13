<?php
/**
 * @file
 * Administrative pages for Stanford CAP API module.
 */

define('ENTRY_PER_PAGE', 25);

/**
 * Form builder for details page.
 */
function stanford_cap_api_details_form($form, &$form_state) {

  // @todo Check connection status here.
  $status = FALSE;
  $status_message = t("Currently, your site can't connect to CAP API.");
  if ($status) {
    $status_message = t('Currently, your site can connect to CAP API.');
  }

  $form['status_wrapper'] = array(
    '#type' => 'container',
  );
  $form['status_wrapper']['status'] = array(
    '#markup' => $status_message,
  );

  $query = new EntityFieldQuery();
  $count = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'cap_faculty_profile')
    ->count()
    ->execute();
  $form['count_wrapper'] = array(
    '#type' => 'container',
  );
  $form['count_wrapper']['count'] = array(
    '#markup' => t('There are %count CAP profiles being synchronized with your website.', array('%count' => $count)),
  );

  $sync_date_stamp = variable_get('cap_sync_date', '');
  if (empty($sync_date_stamp)) {
    $sync_text = t('CAP profiles were not synchronized yet.');
  }
  else {
    $sync_text = t('The last time CAP profiles were synchronized was %sync_date.', array('%sync_date' => format_date($sync_date_stamp, 'long')));
  }
  $form['sync_date_wrapper'] = array(
    '#type' => 'container',
  );
  $form['sync_date_wrapper']['sync_date'] = array(
    '#markup' => $sync_text,
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['synchronize'] = array(
    '#type' => 'submit',
    '#value' => t('Synchronize'),
  );

  return $form;
}

/**
 * Details form submit handler.
 */
function stanford_cap_api_details_form_submit() {

  variable_set('cap_sync_date', REQUEST_TIME);
  // @todo Call synchronization here.
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
  $description = 'Please enter the information you use to connect to the'
    . ' CAP API. This will be used for each callback to the CAP API itself.';
  $form['connection']['description_wrapper']['description'] = array(
    '#markup' => t($description),
  );

  $form['connection']['cap_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username:'),
    '#default_value' => variable_get('cap_username', ''),
  );

  $form['connection']['cap_password'] = array(
    '#type' => 'password',
    '#title' => t('Password:'),
  );

  $form['synchronization'] = array(
    '#type' => 'fieldset',
    '#title' => t('Synchronization information'),
  );

  $form['synchronization']['description_wrapper'] = array(
    '#type' => 'container',
  );
  $description = 'There are several options for how synchronization with the'
    . ' CAP API can be handled.';
  $form['synchronization']['description_wrapper']['description'] = array(
    '#markup' => t($description),
  );

  $custom_fields_description = 'Check this box to allow users to add / edit'
    . ' / modify fields that are part of faculty profiles. This will allow'
    . ' administrators to customize the information that is stored as part of'
    . ' each CAP profile.';
  $form['synchronization']['cap_custom_fields'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow user to create custom fields?'),
    '#description' => t($custom_fields_description),
    '#default_value' => variable_get('cap_custom_fields', FALSE),
  );

  $custom_fields_description = 'Check this box to allow users to edit the'
    . ' information contained in a CAP profile. Editing a profile will cause'
    . ' information to be changed for profiles displayed on this website only,'
    . ' and changes will not be synchronized back up to the CAP system.';
  $form['synchronization']['cap_allow_edit'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow user to edit CAP profile information?'),
    '#description' => t($custom_fields_description),
    '#default_value' => variable_get('cap_allow_edit', FALSE),
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
    '#default_value' => variable_get('cap_api_base_url', 'http://irt-dev.stanford.edu/cap-api'),
  );

  $form['advanced']['cap_auth_uri'] = array(
    '#type' => 'textfield',
    '#title' => t('Authentication URI'),
    '#description' => t('CAP API authentication URL.'),
    '#default_value' => variable_get('cap_auth_uri', 'https://authz-test.stanford.edu/oauth/token'),
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
  $auth_token = stanford_cap_api_auth($form_state['values']['cap_username'], $form_state['values']['cap_password']);
  if (!$auth_token) {
    $msg = "Error. Can't connect to Stanford CAP API."
      . " Please check your username and password.";
    form_set_error('cap_username', t($msg));
    form_set_error('cap_password');
  }
}

/**
 * Submit handler for settings form.
 */
function stanford_cap_api_settings_form_submit($form, &$form_state) {
  $config_vars = array(
    'cap_username',
    'cap_password',
    'cap_custom_fields',
    'cap_allow_edit',
    'cap_api_base_url',
    'cap_auth_uri',
  );
  foreach ($config_vars as $config_var) {
    variable_set($config_var, $form_state['values'][$config_var]);
  }
  drupal_set_message(t('Configuration saved.'));
}

/**
 * Form builder for import page.
 */
function stanford_cap_api_import_form($form, &$form_state) {

  $values = isset($form_state['values']) ? $form_state['values'] : array();

  $form['description_wrapper'] = array(
    '#type' => 'container',
  );
  $description = 'CAP Profiles can be imported into the system by identifying'
    . ' the correct faculty members to add to your website. Select faculty'
    . ' profiles using the tools below, and you can select specific profiles'
    . ' from the next screen.';
  $form['description_wrapper']['description'] = array(
    '#markup' => t($description),
  );

  $form['header'] = array(
    '#prefix' => '<h3>',
    '#markup' => t('Import CAP profiles'),
    '#suffix' => '</h3>',
  );

  $form['first_name'] = array(
    '#type' => 'textfield',
    '#title' => t('First name'),
    '#default_value' => isset($values['first_name']) ? $values['first_name'] : '',
  );

  $form['last_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Last name'),
    '#default_value' => isset($values['last_name']) ? $values['last_name'] : '',
  );

  $options = array();
  $form['school'] = array(
    '#type' => 'select',
    '#title' => t('School / Department'),
    '#options' => $options,
    '#empty_option' => t('--Please select--'),
    '#empty_value' => '',
    '#default_value' => isset($values['school']) ? $values['school'] : '',
    '#disabled' => TRUE,
  );

  $form['organization'] = array(
    '#type' => 'textfield',
    '#title' => t('Organization'),
    '#default_value' => isset($values['organization']) ? $values['organization'] : '',
  );

  $form['workgroup'] = array(
    '#type' => 'textfield',
    '#title' => t('Workgroup'),
    '#default_value' => isset($values['workgroup']) ? $values['workgroup'] : '',
  );

  $form['university_id'] = array(
    '#type' => 'textfield',
    '#title' => t('University ID'),
    '#default_value' => isset($values['university_id']) ? $values['university_id'] : '',
  );

  $form['sunet_id'] = array(
    '#type' => 'textfield',
    '#title' => t('SUNet ID'),
    '#default_value' => isset($values['sunet_id']) ? $values['sunet_id'] : '',
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
  );

  return $form;
}

/**
 * Submit handler for import form.
 */
function stanford_cap_api_import_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  $params = array('ps' => ENTRY_PER_PAGE);

  if (!empty($values['first_name'])) {
    $params['name'] = check_plain($values['first_name']);
  }
  if (!empty($values['last_name'])) {
    if (isset($params['name'])) {
      $params['name'] .= ' ' . check_plain($values['last_name']);
    }
    else {
      $params['name'] = check_plain($values['last_name']);
    }
  }
  if (!empty($values['organization'])) {
    $params['orgCodes'] = _cap_api_prepare_list_str($values['organization']);
  }
  if (!empty($values['workgroup'])) {
    $params['privGroups'] = _cap_api_prepare_list_str($values['workgroup']);
  }
  if (!empty($values['university_id'])) {
    $params['universityId'] = check_plain($values['university_id']);
  }
  if (!empty($values['sunet_id'])) {
    $params['uid'] = check_plain($values['sunet_id']);
  }

  $_SESSION['search_params'] = $params;
  $_SESSION['search_response'] = stanford_cap_api_request('/api/profiles/v1', $params);

  $form_state['redirect'] = 'admin/config/cap/import/result';
}

/**
 * Helper to prepare list for search.
 *
 * Input string could contain white space or special chars which not good for
 * API call.
 *
 * @param string $str
 *   String containing list.
 *
 * @return string
 *   Prepared string.
 */
function _cap_api_prepare_list_str($str) {

  $list = explode(',', $str);
  array_walk($list, 'check_plain');
  array_walk($list, 'trim');

  return implode(',', $list);
}

/**
 * Form builder for import result page.
 */
function stanford_cap_api_import_result_form($form, &$form_state) {

  if (!empty($_SESSION['search_response'])) {

    $form['description_wrapper'] = array(
      '#type' => 'container',
    );
    $link = l(t('Start new search.'), 'admin/config/cap/import');
    $description = 'Please select the CAP profiles you would like to import'
      . ' into your site. !link';
    $form['description_wrapper']['description'] = array(
      '#markup' => t($description, array('!link' => $link)),
    );

    $form['results_wrapper'] = array(
      '#type' => 'container',
    );

    if (isset($_GET['page']) && is_numeric($_GET['page'])) {
      $page_num = (int) $_GET['page'] + 1;
    }
    else {
      $page_num = 1;
    }
    $search_params = $_SESSION['search_params'];
    if ($page_num != 1) {
      $search_params['p'] = $page_num;
      $_SESSION['search_response'] = stanford_cap_api_request('/api/profiles/v1', $search_params);
      $search_response = $_SESSION['search_response'];
    }
    else {
      if ($_SESSION['search_response']['page'] == $page_num) {
        $search_response = $_SESSION['search_response'];
      }
      else {
        $search_params['p'] = $page_num;
        $_SESSION['search_response'] = stanford_cap_api_request('/api/profiles/v1', $search_params);
        $search_response = $_SESSION['search_response'];
      }
    }

    $start = $search_response['firstPage'] ? 1 : ENTRY_PER_PAGE * ($search_response['page'] - 1) + 1;
    $end = $search_response['lastPage'] ? $search_response['totalCount'] : ENTRY_PER_PAGE * $search_response['page'];
    $total = $search_response['totalCount'];

    $form['results_wrapper']['results'] = array(
      '#markup' => t('Viewing profiles @start - @end of @total.', array(
        '@start' => $start,
        '@end' => $end,
        '@total' => $total,
      )),
    );

    $header = array(
      'name' => t('Name'),
      'link' => t('Profile link'),
    );
    $options = array();
    foreach ($search_response['values'] as $profile) {
      $options[$profile['profileId']] = array(
        'name' => array(
          'data' => array(
            '#type' => 'link',
            '#title' => check_plain($profile['displayName']),
            '#href' => 'https://med.stanford.edu/profiles/auth/frdActionServlet?choiceId=profile&fid=' . $profile['profileId'],
          ),
        ),
        'link' => array(
          'data' => array(
            '#type' => 'link',
            '#title' => t('View in CAP'),
            '#href' => 'https://med.stanford.edu/profiles/auth/frdActionServlet?choiceId=profile&fid=' . $profile['profileId'],
          ),
        ),
      );
    }
    $form['profiles'] = array(
      '#type' => 'tableselect',
      '#header' => $header,
      '#options' => $options,
    );
    $element = 0;
    $parameters = array();
    $quantity = 9;
    global $pager_page_array, $pager_total;
    $pager_page_array = array($element => $page_num - 1);
    $pager_total = array($element => $search_response['totalPages']);

    $form['pager'] = array(
      '#markup' => theme_pager(array(
        'tags' => array(),
        'element' => $element,
        'parameters' => $parameters,
        'quantity' => $quantity,
      )),
    );

    $form['actions'] = array('#type' => 'actions');
    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Import profiles'),
    );
  }
  else {
    $form['description_wrapper'] = array(
      '#type' => 'container',
    );
    $description = "Search has returned no results. !link";
    $link = l(t('Want to try again?'), 'admin/config/cap/import');
    $form['description_wrapper']['description'] = array(
      '#markup' => t($description, array('!link' => $link)),
    );
  }

  return $form;
}

/**
 * Submit handler for import result form.
 */
function stanford_cap_api_import_result_form_submit($form, &$form_state) {
  // @todo Import should happen here.
  drupal_set_message(t('Imported!'));
}

/**
 * Form builder for import result page.
 */
function stanford_cap_api_profile_test($form, &$form_state) {
  $form['description_wrapper'] = array(
    '#type' => 'container',
  );
  $description = 'Please use the options below to test the faculty profile'
    . ' structure synchronization.';
  $form['description_wrapper']['description'] = array(
    '#markup' => $description,
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['sync'] = array(
    '#type' => 'submit',
    '#value' => t('Synchronize fields in the faculty profile'),
    '#submit' => array('stanford_cap_api_test_synchronize'),
  );
  $form['actions']['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset faculty profile content type.'),
    '#submit' => array('stanford_cap_api_reset'),
  );

  return $form;
}

function stanford_cap_api_test_synchronize() {

  $fields_from_service = array(
    'homepage' => array(
      'type' => 'link',
      'label' => 'Homepage',
    ),
    'birthdate' => array(
      'type' => 'date',
      'label' => 'Date of birth',
    ),
    'fullname' => array(
      'type' => 'string',
      'label' => 'Full name',
    ),
    'honors' => array(
      'type' => 'text',
      'label' => 'Honors and awards',
    ),
    'background' => array(
      'type' => 'text',
      'label' => 'Professional background',
    ),
  );
  timer_start('fields_sync');
  stanford_cap_api_synchronize_fields($fields_from_service);
  $timer = timer_stop('fields_sync');
  drupal_set_message(t('Fields successfully synchronized.'));
  drupal_set_message(t('This operation took %time seconds.', array('%time' => floor($timer['time'] / 1000))));
}

function stanford_cap_api_reset() {
  $fields = db_select('cap_api_fields', 'f')->fields('f', array('field_name'))
    ->execute()->fetchCol();
  foreach ($fields as $field) {
    field_delete_field($field);
  }
  field_purge_batch(10);
  db_delete('cap_api_fields')->execute();
  drupal_set_message(t('Faculty profile content type has being resetted to default.'));
}

/**
 * Manage profiles page callback.
 */
function stanford_cap_api_manage() {
  return views_embed_view('cap_api_manage_profiles');
}
