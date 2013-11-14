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

  // checkboxes, used to display status and icons
  $checkbox = '<div class="cap_checkbox cap_cannot_connect"><span></span></div>';
  $countbox = '<div class="cap_checkbox cap_total"><span>%count</span></div>';
  $datebox = '<div class="cap_checkbox cap_date"><span>%count</span></div>';
  
  // add the status message
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

  $query = new EntityFieldQuery();
  $count = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'cap_faculty_profile')
    ->count()
    ->execute();
    
  // text for the count of profiles
  $countbox = t($countbox, array('%count' => $count));
  $count_text = $countbox . t('CAP profile(s) are being stored in your website.');
  $import_groups = l(t('importing groups'), 'admin/config/cap/group');
  $import_people = l(t('importing individual profiles'), 'admin/config/cap/import');
    
  $count_text .= t('<br><em class="cap_additional">You can add more by ') . $import_groups . ' or ' . $import_people . '.</em>';
  
  $form['count_wrapper'] = array(
    '#type' => 'container',
    '#prefix' => '<div class="cap_info_wrapper">',
    '#suffix' => '<div class="clearfix"></div></div>',
    );
  $form['count_wrapper']['count'] = array(
    '#markup' => $count_text,
  );

  $sync_date_stamp = variable_get('stanford_cap_api_cron_last_run', 0);
  
  $diff = round((time() - $sync_date_stamp)/60/60);
  $datebox = t($datebox, array('%count' => $diff));
  
  if (empty($sync_date_stamp)) {
    $sync_text = t('CAP profiles were not sync yet.');
  }
  else {
    $sync_text = t('Hour(s) since last sync.');
  }
  $sync_text .= t('<br><em class="cap_additional">You can adjust the frequency of updates on the ') . l('settings page', 'admin/config/cap/settings') . '.</em>';
  
  
  
  $form['sync_date_wrapper'] = array(
    '#type' => 'container',
    '#prefix' => '<div class="cap_info_wrapper">',
    '#suffix' => '<div class="clearfix"></div></div>',
    );
  $form['sync_date_wrapper']['sync_date'] = array(
    '#markup' => $datebox . $sync_text,
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

  variable_set('stanford_cap_api_cron_last_run', REQUEST_TIME);
  $batch = array(
    'title' => t('Synchronizing profiles'),
    'operations' => array(array('stanford_cap_api_update_profiles', array())),
  );
  batch_set($batch);
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
    '#title' => t('Profile Editing'),
  );

  $form['synchronization']['description_wrapper'] = array(
    '#type' => 'container',
  );
  $description = 'These options allow authorized users to change the structure and content of CAP profiles. Please note, any changes to profiles will be ';
  $description .= 'specific to this site, and will not make their way back up to CAP.';
    
    
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

  $form['refresh'] = array(
    '#type' => 'fieldset',
    '#title' => t('Refresh Options'),
  );

  $form['refresh']['cap_profile_update'] = array(
    '#type' => 'radios',
    '#title' => t('CAP Profiles can be updated regularly to ensure you have the latest content available for the site:'),
    '#default_value' => variable_get('cap_profile_update', 'nightly'),
    '#options' => array(
      'viewing' => t('When viewing the profile.'),
      'nightly' => t('Nightly.'),
    ),
  );

  $form['orphaned'] = array(
    '#type' => 'fieldset',
    '#title' => t('Orphaned profiles'),
  );

  $options = array(
    'unpublish' => t('Put the profile in an unpublished state.'),
    'nothing' => t('Do nothing. The profile will simply continue to exist on the website.'),
    'remove' => t('Remove it from the site.'),
  );
  $form['orphaned']['orphaned_profile_action'] = array(
    '#type' => 'radios',
    '#title' => t('When a profile is removed from the CAP API:'),
    '#default_value' => variable_get('cap_orphaned_profile_action', 'unpublish'),
    '#options' => $options,
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
  if (!empty($form_state['values']['cap_username']) && !empty($form_state['values']['cap_password'])) {
    $auth_token = stanford_cap_api_auth($form_state['values']['cap_username'], $form_state['values']['cap_password']);
    if (!$auth_token) {
      $msg = "Error. Can't connect to Stanford CAP API."
        . " Please check your username and password.";
      form_set_error('cap_username', t($msg));
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
  variable_set('cap_custom_fields', $values['cap_custom_fields']);
  variable_set('cap_allow_edit', $values['cap_allow_edit']);
  variable_set('cap_orphaned_profile_action', $values['orphaned_profile_action']);
  variable_set('cap_profile_update', $values['cap_profile_update']);
  drupal_set_message(t('Configuration saved.'));
  // Check if we have organizations imported.
  $ids = db_select('cap_api_orgs', 'orgs')
    ->fields('orgs', array('id'))
    ->execute()
    ->fetchCol();
  if (empty($ids) && !empty($values['cap_username']) && !empty($values['cap_password'])) {
    stanford_cap_api_import_organizations();
  }
}

/**
 * Form builder for import page.
 */
function stanford_cap_api_import_form($form, &$form_state) {

  $form['description_wrapper'] = array(
    '#type' => 'container',
  );
  $description = 'Individual CAP Profiles can be imported into the system by identifying'
    . ' the correct faculty members to add to your website. Use the tools below to search for '
    . ' individual profiles, and you can select specific profiles for import '
    . '  on the next screen.';
    
  $form['description_wrapper']['description'] = array(
    '#markup' => t($description),
  );

  $form['header'] = array(
    '#prefix' => '<h3>',
    '#markup' => t('Import CAP profiles'),
    '#suffix' => '</h3>',
  );

  $name_desc = 'Please enter a name to search for. You can search using a partial match, or by selecting from the list of suggested names.';
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('First name / Last name'),
    '#autocomplete_path' => 'stanford-cap-api-user-autocomplete',
    '#description' => t($name_desc),
  );

  /**
   * Disabling this field until we get a better explanation of how it works from MEDIRT
   * @TODO: get better documentation on this field
   */
  /*
  $form['school'] = array(
    '#type' => 'textfield',
    '#title' => t('Organization alias'),
  );
  */

  $org_description = 'Please select the name of the organization you wish to import. You can learn more about Stanford University Org Code'
    . ' Hierarchy !here.';
  $url = 'http://www.stanford.edu/dept/pres-provost/budget/org/orgchart/';
    
  $form['organization'] = array(
    '#type' => 'hierarchical_select',
    '#title' => t('Organization'),
    '#size' => 1,
    '#config' => array(
      'module' => 'stanford_cap_api',
      'params' => array(),
      'save_lineage' => 0,
      'enforce_deepest' => 0,
      'entity_count' => 0,
      'require_entity' => 0,
      'resizable' => 1,
      'level_labels' => array(
        'status' => 0,
        'labels' => array(
          0 => t('University'),
        ),
      ),
      'dropbox' => array(
        'status' => 0,
        'title' => t('All selections'),
        'limit' => 0,
        'reset_hs' => 1,
      ),
      'editability' => array(
        'status' => 0,
        'item_types' => array(),
        'allowed_levels' => array(
          0 => 0,
          1 => 0,
          2 => 0,
        ),
        'allow_new_levels' => 0,
        'max_levels' => 3,
      ),
      'animation_delay' => 400,
      'special_items' => array(),
      'render_flat_select' => 0,
    ),
    '#default_value' => 'none',
    '#description' => t($org_description, array('!here' => l(t('by clicking here'), $url))),
  );

  
  $workgroup_desc = t('Please enter the name of the workgroup you wish to import. You can learn more about workgroups at Stanford, and get proper names for import, !here');
  $url = 'https://workgroup.stanford.edu';
  
  $form['workgroup'] = array(
    '#type' => 'textfield',
    '#title' => t('Workgroup'),
    '#description'    => t($workgroup_desc, array('!here' => l(t('at the workgroup manager website.'), $url))),
  );

  $uiddesc = t('Please enter the university id for the profile you wish to import.');
  
  $form['university_id'] = array(
    '#type' => 'textfield',
    '#title' => t('University ID'),
    '#description'    => t($uiddesc),
  );

  $sunetdesc = t('Please enter SUNET ids for the profiles you wish to import. You can enter multiple SUNET IDs by separating them with a comma.');
  $form['sunet_id'] = array(
    '#type' => 'textarea',
    '#title' => t('SUNet ID'),
    '#description' => t($sunetdesc),
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

  if (!empty($values['name'])) {
    $params['name'] = check_plain($values['name']);
  }
  if (!empty($values['organization'][0])) {
    $org_codes = db_select('cap_api_orgs', 'orgs')
      ->condition('orgid', $values['organization'][0])
      ->fields('orgs', array('orgCodes'))->execute()->fetchField();
    $params['orgCodes'] = implode(',', unserialize($org_codes));
  }
  if (!empty($values['workgroup'])) {
    $params['privGroups'] = _stanford_cap_api_prepare_list_str($values['workgroup']);
  }
  if (!empty($values['university_id'])) {
    $params['universityId'] = check_plain($values['university_id']);
  }
  if (!empty($values['school'])) {
    $params['orgAlias'] = check_plain($values['school']);
  }
  if (!empty($values['sunet_id'])) {
    $params['ids'] = _stanford_cap_api_prepare_list_str($values['sunet_id']);
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
function _stanford_cap_api_prepare_list_str($str) {
  // Replace all Windows, Unix and Mac newlines by commas.
  $str = str_replace(array("\r\n", "\r", "\n"), ',', $str);
  $list = explode(',', $str);
  array_walk($list, 'check_plain');
  $list = array_map('trim', $list);

  return implode(',', $list);
}

/**
 * Form builder for import result page.
 */
function stanford_cap_api_import_result_form($form, &$form_state) {

  if (!empty($_SESSION['search_response']) && !empty($_SESSION['search_response']['values'])) {
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
      $href = _stanford_cap_api_get_cap_profile_url($profile);

      $options[$profile['profileId']] = array(
        'name' => array(
          'data' => array(
            '#type' => 'link',
            '#title' => check_plain($profile['displayName']),
            '#href' => $href,
          ),
        ),
        'link' => array(
          'data' => array(
            '#type' => 'link',
            '#title' => t('View in CAP'),
            '#href' => $href,
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

  if (empty($form_state['values']['profiles'])) {
    drupal_set_message(t('Nothing to import. Profiles list is empty.'));
  }
  else {
    $profiles = $form_state['values']['profiles'];
    $operations = array();
    foreach ($profiles as $profile) {
      if ($profile != 0) {
        $operations[] = array(
          'stanford_cap_api_profile_import',
          array($profile),
        );
      }
    }

    $batch = array(
      'title' => t('Importing profiles'),
      'operations' => $operations,
      'progress_message' => t('Current: @current | Remaining:
    @remaining | Total: @total | Percentage: @percentage | Estimate:
    @estimate | Elapsed: @elapsed'),
      'finished' => 'stanford_cap_api_import_result_finished',
    );
    batch_set($batch);
  }
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
    '#value' => t('Reset faculty profile content type'),
    '#submit' => array('stanford_cap_api_reset'),
  );

  return $form;
}

/**
 * Forces module to synchronize CAP profile fields structure.
 */
function stanford_cap_api_test_synchronize() {
  timer_start('fields_sync');
  stanford_cap_api_synchronize_schema();
  $timer = timer_stop('fields_sync');
  drupal_set_message(t('Fields successfully synchronized.'));
  drupal_set_message(t('This operation took %time seconds.', array('%time' => floor($timer['time'] / 1000))));
}

/**
 * Remove all CAP profile fields from system.
 */
function stanford_cap_api_reset() {
  $fields = db_select('cap_api_fields', 'f')->fields('f', array('field_name'))
    ->execute()->fetchCol();
  foreach ($fields as $field) {
    field_delete_field($field);
  }
  $deleted_fields = field_read_instances(array('deleted' => 1), array('include_deleted' => 1));
  $operations = array();
  foreach ($deleted_fields as $deleted_field) {
    $operations[] = array(
      'field_purge_batch',
      array(1),
    );
  }
  batch_set(array('operations' => $operations));
  db_delete('cap_api_fields')->execute();
  drupal_set_message(t('Faculty profile content type has being resetted to default.'));
}

/**
 * Manage profiles page callback.
 */
function stanford_cap_api_manage() {
  return views_embed_view('cap_api_manage_profiles');
}

/**
 * Groups synchronization from builder.
 */
function stanford_cap_api_group_sync_form($form, &$form_state) {

  $form['description_wrapper'] = array(
    '#type' => 'container',
  );
  $description = 'CAP profiles associated with specific groups can be'
    . ' automatically synced with this site on an ongoing basis. Use the tools'
    . ' on this page to manage the groups that are synced with the site.';
  $form['description_wrapper']['description'] = array(
    '#markup' => t($description),
  );

  if (empty($form_state['values'])) {

    $form['groups'] = array(
      '#type' => 'fieldset',
      '#title' => t('Groups being synced'),
    );

    $groups = db_select('cap_api_sync_groups', 'groups')
      ->fields('groups')
      ->execute()
      ->fetchAll();
    $header = array(
      t('Name'),
      t('Profiles synchronized'),
      t('Last synced date'),
      t('Operations'),
    );
    $rows = array();
    foreach ($groups as $group) {
      $delete_link = l(t('Remove'), 'admin/config/cap/group/' . $group->id . '/delete');
      $sync_link = l(t('Sync now'), 'admin/config/cap/group/' . $group->id . '/sync');
      $rows[] = array(
        check_plain($group->name),
        t('%count profiles', array('%count' => $group->count)),
        $group->lastsynced ? format_date($group->lastsynced, 'long') : t('Never'),
        $delete_link . ' | ' . $sync_link,
      );
    }
    $empty = 'No groups were saved for synchronization yet.';

    $table = theme('table', array(
      'header' => $header,
      'rows' => $rows,
      'empty' => t($empty),
    ));

    $form['groups']['groups_list'] = array(
      '#markup' => $table,
    );

    $form['new_group'] = array(
      '#type' => 'fieldset',
      '#title' => t('Add new group'),
    );

    /**
     * Removing this for now, does not appear in the API
     * @TODO: confirm with Darryl how the name search works for orgs
     */
    /*
    $form['new_group']['school'] = array(
      '#type' => 'textfield',
      '#title' => t('School/Department'),
    );
    */

    $org_description = 'Please select the name of the organization you wish to import. You can learn more about Stanford University Org Code'
      . ' Hierarchy !here.';
    $url = 'http://www.stanford.edu/dept/pres-provost/budget/org/orgchart/';
    $form['new_group']['organization'] = array(
      '#type' => 'hierarchical_select',
      '#title' => t('Organization'),
      '#description' => t($org_description, array('!here' => l(t('by clicking here'), $url))),
      '#size' => 1,
      '#config' => array(
        'module' => 'stanford_cap_api',
        'params' => array(),
        'save_lineage' => 0,
        'enforce_deepest' => 0,
        'entity_count' => 0,
        'require_entity' => 0,
        'resizable' => 1,
        'level_labels' => array(
          'status' => 0,
          'labels' => array(
            0 => t('University'),
          ),
        ),
        'dropbox' => array(
          'status' => 0,
          'title' => t('All selections'),
          'limit' => 0,
          'reset_hs' => 1,
        ),
        'editability' => array(
          'status' => 0,
          'item_types' => array(),
          'allowed_levels' => array(
            0 => 0,
            1 => 0,
            2 => 0,
          ),
          'allow_new_levels' => 0,
          'max_levels' => 3,
        ),
        'animation_delay' => 400,
        'special_items' => array(),
        'render_flat_select' => 0,
      ),
      '#default_value' => 'none',
    );

    
    $workgroup_desc = t('Please enter the name of the workgroup you wish to import. You can learn more about workgroups at Stanford, and get proper names for import, !here');
    $url = 'https://workgroup.stanford.edu';
    
    
    $form['new_group']['workgroup'] = array(
      '#type'           => 'textfield',
      '#title'          => t('Workgroup'),
      '#description'    => t($workgroup_desc, array('!here' => l(t('at the workgroup manager website.'), $url))),
    );

    $form['new_group']['search'] = array(
      '#type' => 'submit',
      '#value' => t('Search'),
    );
  }
  else {
    $form['groups'] = array(
      '#type' => 'fieldset',
      '#title' => t('Search results'),
    );

    $header = array(
      'name' => t('Group'),
      'profiles' => t('Profiles in group'),
    );
    $options = array();
    $group_types = array('organization', 'workgroup');
    $form['groups_to_save'] = array(
      '#type' => 'container',
      '#tree' => TRUE,
    );

    foreach ($group_types as $group_type) {
      switch ($group_type) {
        case 'organization':
          $org_codes = db_select('cap_api_orgs', 'orgs')
            ->condition('orgid', $form_state['values'][$group_type][0])
            ->fields('orgs', array('orgCodes'))->execute()->fetchField();
          $name = '';
          if (!empty($org_codes)) {
            $name = implode(',', unserialize($org_codes));
          }
          break;

        default:
          $name = check_plain(trim($form_state['values'][$group_type]));
          break;
      }
      if (!empty($name)) {
        $count = _stanford_cap_api_get_group_profiles_count($group_type, $name);
        $label = check_plain($name);
        if ($group_type == 'organization') {
          $label = stanford_cap_api_hierarchical_select_item_get_label($form_state['values'][$group_type][0]);
        }
        $options[$group_type] = array('name' => $label, 'profiles' => $count);
        $form['groups_to_save'][$group_type] = array(
          '#type' => 'value',
          '#value' => $name,
        );
      }
    }

    $form['groups']['groups_list'] = array(
      '#type' => 'tableselect',
      '#header' => $header,
      '#options' => $options,
    );

    $form['groups']['save'] = array(
      '#type' => 'submit',
      '#value' => t('Save selected groups'),
    );
  }

  return $form;
}

/**
 * Groups synchronization from submit handler.
 */
function stanford_cap_api_group_sync_form_submit($form, &$form_state) {
  if (!empty($form_state['values']['organization'][0]) || !empty($form_state['values']['workgroup']) || !empty($form_state['values']['school'])) {
    $form_state['rebuild'] = TRUE;
  }
  if (isset($form_state['values']['groups_list'])) {
    $operations = array();
    foreach ($form_state['values']['groups_list'] as $group_type) {
      if (isset($form_state['values']['groups_to_save'][$group_type])) {
        $group_name = $form_state['values']['groups_to_save'][$group_type];
        $operations[] = array(
          '_stanford_cap_api_sync_group_wrapper',
          array($group_type, $group_name),
        );
      }
    }
    $batch = array(
      'title' => t('Synchronizing profile groups'),
      'operations' => $operations,
      'progress_message' => t('Current: @current | Remaining:
    @remaining | Total: @total | Percentage: @percentage | Estimate:
    @estimate | Elapsed: @elapsed'),
    );
    batch_set($batch);
  }
}

/**
 * Helper to get group profiles count.
 *
 * @param string $type
 *   Group type.
 * @param string $name
 *   Group name.
 *
 * @return int
 *   Number of profiles in this group.
 */
function _stanford_cap_api_get_group_profiles_count($type, $name) {
  $count = 0;
  switch ($type) {
    case 'organization':
      $params = array('orgCodes' => $name);
      $data = stanford_cap_api_request('/api/profiles/v1', $params);
      if ($data) {
        $count = $data['totalCount'];
      }
      break;

    case 'workgroup':
      $params = array('privGroups' => $name);
      $data = stanford_cap_api_request('/api/profiles/v1', $params);
      if ($data) {
        $count = $data['totalCount'];
      }
      break;

    case 'school':
      break;
  }

  return $count;
}

/**
 * Drop profiles group from synchronization form builder.
 */
function stanford_cap_api_group_sync_drop_form($form, &$form_state, $id) {
  $form_addition = array('id' => array('#type' => 'value', '#value' => $id));
  $question = t('Are you sure you want to stop syncing this group?');

  return confirm_form($form_addition, $question, 'admin/config/cap/group', NULL, t('Delete'));
}

/**
 * Drop profiles group from synchronization form submit handler..
 */
function stanford_cap_api_group_sync_drop_form_submit($form, &$form_state) {
  stanford_cap_api_sync_group_drop($form_state['values']['id']);
  $form_state['redirect'] = 'admin/config/cap/group';
  drupal_set_message(t('Group was successfully deleted.'));
}

/**
 * Starts profiles group synchronization.
 */
function stanford_cap_api_group_sync_now($id) {
  $group = db_select('cap_api_sync_groups', 'groups')
    ->condition('id', $id)
    ->fields('groups')
    ->execute()
    ->fetchAssoc();
  $operations = array();
  $operations[] = array(
    '_stanford_cap_api_sync_group_wrapper',
    array($group['type'], $group['name']),
  );

  $batch = array(
    'title' => t('Synchronizing profile groups'),
    'operations' => $operations,
    'progress_message' => t('Current: @current | Remaining:
    @remaining | Total: @total | Percentage: @percentage | Estimate:
    @estimate | Elapsed: @elapsed'),
  );
  batch_set($batch);
  batch_process('admin/config/cap/group');
}

/**
 * Menu callback for CAP profiles name autocomplete.
 *
 * @param string $str
 *   String to search for.
 */
function stanford_cap_api_user_autocomplete($str = '') {
  $matches = array();
  if ($str) {
    $response = stanford_cap_api_request('/api/cap/v1/search/autocomplete', array('q' => $str));
    if (!empty($response['count'])) {
      foreach ($response['values'] as $match) {
        $matches[$match['name']] = $match['name'];
      }
    }
  }

  drupal_json_output($matches);
}

/**
 * Checks that we can connect to CAP API.
 */
function stanford_cap_api_auth_status() {
  if (stanford_cap_api_get_profile_schema()) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}
