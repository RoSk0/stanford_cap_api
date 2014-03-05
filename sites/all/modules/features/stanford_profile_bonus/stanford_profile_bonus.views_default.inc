<?php
/**
 * @file
 * stanford_profile_bonus.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_profile_bonus_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'stanford_profiles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford profiles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Stanford profiles';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Academic Long Title (cap_longtitle) */
  $handler->display->display_options['relationships']['cap_longtitle_value']['id'] = 'cap_longtitle_value';
  $handler->display->display_options['relationships']['cap_longtitle_value']['table'] = 'field_data_cap_longtitle';
  $handler->display->display_options['relationships']['cap_longtitle_value']['field'] = 'cap_longtitle_value';
  $handler->display->display_options['relationships']['cap_longtitle_value']['label'] = 'Long title';
  $handler->display->display_options['relationships']['cap_longtitle_value']['delta'] = '-1';
  /* Relationship: Content: Affiliation Flags (cap_affiliations) */
  $handler->display->display_options['relationships']['cap_affiliations_value']['id'] = 'cap_affiliations_value';
  $handler->display->display_options['relationships']['cap_affiliations_value']['table'] = 'field_data_cap_affiliations';
  $handler->display->display_options['relationships']['cap_affiliations_value']['field'] = 'cap_affiliations_value';
  $handler->display->display_options['relationships']['cap_affiliations_value']['label'] = 'Affiliations';
  $handler->display->display_options['relationships']['cap_affiliations_value']['delta'] = '-1';
  /* Field: Content: CAP profile image */
  $handler->display->display_options['fields']['cap_profile_image']['id'] = 'cap_profile_image';
  $handler->display->display_options['fields']['cap_profile_image']['table'] = 'field_data_cap_profile_image';
  $handler->display->display_options['fields']['cap_profile_image']['field'] = 'cap_profile_image';
  $handler->display->display_options['fields']['cap_profile_image']['label'] = '';
  $handler->display->display_options['fields']['cap_profile_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cap_profile_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['cap_profile_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field collection item: Label */
  $handler->display->display_options['fields']['cap_label_2']['id'] = 'cap_label_2';
  $handler->display->display_options['fields']['cap_label_2']['table'] = 'field_data_cap_label_2';
  $handler->display->display_options['fields']['cap_label_2']['field'] = 'cap_label_2';
  $handler->display->display_options['fields']['cap_label_2']['relationship'] = 'cap_longtitle_value';
  $handler->display->display_options['fields']['cap_label_2']['label'] = '';
  $handler->display->display_options['fields']['cap_label_2']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cap_stanford_profile' => 'cap_stanford_profile',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: CAP profile organization (field_cap_profile_organization) */
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['id'] = 'field_cap_profile_organization_tid';
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['table'] = 'field_data_field_cap_profile_organization';
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['field'] = 'field_cap_profile_organization_tid';
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['value'] = '';
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['expose']['operator_id'] = 'field_cap_profile_organization_tid_op';
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['expose']['label'] = 'Organization';
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['expose']['operator'] = 'field_cap_profile_organization_tid_op';
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['expose']['identifier'] = 'field_cap_profile_organization_tid';
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['vocabulary'] = 'stanford_org_code_hierarchy';
  /* Filter criterion: Field collection item: capFaculty (cap_capfaculty) */
  $handler->display->display_options['filters']['cap_capfaculty_value']['id'] = 'cap_capfaculty_value';
  $handler->display->display_options['filters']['cap_capfaculty_value']['table'] = 'field_data_cap_capfaculty';
  $handler->display->display_options['filters']['cap_capfaculty_value']['field'] = 'cap_capfaculty_value';
  $handler->display->display_options['filters']['cap_capfaculty_value']['relationship'] = 'cap_affiliations_value';
  $handler->display->display_options['filters']['cap_capfaculty_value']['group'] = 2;
  $handler->display->display_options['filters']['cap_capfaculty_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['cap_capfaculty_value']['expose']['operator_id'] = 'cap_capfaculty_value_op';
  $handler->display->display_options['filters']['cap_capfaculty_value']['expose']['label'] = 'capFaculty';
  $handler->display->display_options['filters']['cap_capfaculty_value']['expose']['operator'] = 'cap_capfaculty_value_op';
  $handler->display->display_options['filters']['cap_capfaculty_value']['expose']['identifier'] = 'cap_capfaculty_value';
  $handler->display->display_options['filters']['cap_capfaculty_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['cap_capfaculty_value']['group_info']['label'] = 'capFaculty (cap_capfaculty)';
  $handler->display->display_options['filters']['cap_capfaculty_value']['group_info']['identifier'] = 'cap_capfaculty_value';
  $handler->display->display_options['filters']['cap_capfaculty_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['cap_capfaculty_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Field collection item: physician (cap_physician) */
  $handler->display->display_options['filters']['cap_physician_value']['id'] = 'cap_physician_value';
  $handler->display->display_options['filters']['cap_physician_value']['table'] = 'field_data_cap_physician';
  $handler->display->display_options['filters']['cap_physician_value']['field'] = 'cap_physician_value';
  $handler->display->display_options['filters']['cap_physician_value']['relationship'] = 'cap_affiliations_value';
  $handler->display->display_options['filters']['cap_physician_value']['group'] = 2;
  $handler->display->display_options['filters']['cap_physician_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['cap_physician_value']['expose']['operator_id'] = 'cap_physician_value_op';
  $handler->display->display_options['filters']['cap_physician_value']['expose']['label'] = 'physician';
  $handler->display->display_options['filters']['cap_physician_value']['expose']['operator'] = 'cap_physician_value_op';
  $handler->display->display_options['filters']['cap_physician_value']['expose']['identifier'] = 'cap_physician_value';
  $handler->display->display_options['filters']['cap_physician_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Field collection item: capStaff (cap_capstaff) */
  $handler->display->display_options['filters']['cap_capstaff_value']['id'] = 'cap_capstaff_value';
  $handler->display->display_options['filters']['cap_capstaff_value']['table'] = 'field_data_cap_capstaff';
  $handler->display->display_options['filters']['cap_capstaff_value']['field'] = 'cap_capstaff_value';
  $handler->display->display_options['filters']['cap_capstaff_value']['relationship'] = 'cap_affiliations_value';
  $handler->display->display_options['filters']['cap_capstaff_value']['group'] = 2;
  $handler->display->display_options['filters']['cap_capstaff_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['cap_capstaff_value']['expose']['operator_id'] = 'cap_capstaff_value_op';
  $handler->display->display_options['filters']['cap_capstaff_value']['expose']['label'] = 'capStaff';
  $handler->display->display_options['filters']['cap_capstaff_value']['expose']['operator'] = 'cap_capstaff_value_op';
  $handler->display->display_options['filters']['cap_capstaff_value']['expose']['identifier'] = 'cap_capstaff_value';
  $handler->display->display_options['filters']['cap_capstaff_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Field collection item: capPostdoc (cap_cappostdoc) */
  $handler->display->display_options['filters']['cap_cappostdoc_value']['id'] = 'cap_cappostdoc_value';
  $handler->display->display_options['filters']['cap_cappostdoc_value']['table'] = 'field_data_cap_cappostdoc';
  $handler->display->display_options['filters']['cap_cappostdoc_value']['field'] = 'cap_cappostdoc_value';
  $handler->display->display_options['filters']['cap_cappostdoc_value']['relationship'] = 'cap_affiliations_value';
  $handler->display->display_options['filters']['cap_cappostdoc_value']['group'] = 2;
  $handler->display->display_options['filters']['cap_cappostdoc_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['cap_cappostdoc_value']['expose']['operator_id'] = 'cap_cappostdoc_value_op';
  $handler->display->display_options['filters']['cap_cappostdoc_value']['expose']['label'] = 'capPostdoc';
  $handler->display->display_options['filters']['cap_cappostdoc_value']['expose']['operator'] = 'cap_cappostdoc_value_op';
  $handler->display->display_options['filters']['cap_cappostdoc_value']['expose']['identifier'] = 'cap_cappostdoc_value';
  $handler->display->display_options['filters']['cap_cappostdoc_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Field collection item: capMsStudent (cap_capmsstudent) */
  $handler->display->display_options['filters']['cap_capmsstudent_value']['id'] = 'cap_capmsstudent_value';
  $handler->display->display_options['filters']['cap_capmsstudent_value']['table'] = 'field_data_cap_capmsstudent';
  $handler->display->display_options['filters']['cap_capmsstudent_value']['field'] = 'cap_capmsstudent_value';
  $handler->display->display_options['filters']['cap_capmsstudent_value']['relationship'] = 'cap_affiliations_value';
  $handler->display->display_options['filters']['cap_capmsstudent_value']['group'] = 2;
  $handler->display->display_options['filters']['cap_capmsstudent_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['cap_capmsstudent_value']['expose']['operator_id'] = 'cap_capmsstudent_value_op';
  $handler->display->display_options['filters']['cap_capmsstudent_value']['expose']['label'] = 'capMsStudent';
  $handler->display->display_options['filters']['cap_capmsstudent_value']['expose']['operator'] = 'cap_capmsstudent_value_op';
  $handler->display->display_options['filters']['cap_capmsstudent_value']['expose']['identifier'] = 'cap_capmsstudent_value';
  $handler->display->display_options['filters']['cap_capmsstudent_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Field collection item: capPhdStudent (cap_capphdstudent) */
  $handler->display->display_options['filters']['cap_capphdstudent_value']['id'] = 'cap_capphdstudent_value';
  $handler->display->display_options['filters']['cap_capphdstudent_value']['table'] = 'field_data_cap_capphdstudent';
  $handler->display->display_options['filters']['cap_capphdstudent_value']['field'] = 'cap_capphdstudent_value';
  $handler->display->display_options['filters']['cap_capphdstudent_value']['relationship'] = 'cap_affiliations_value';
  $handler->display->display_options['filters']['cap_capphdstudent_value']['group'] = 2;
  $handler->display->display_options['filters']['cap_capphdstudent_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['cap_capphdstudent_value']['expose']['operator_id'] = 'cap_capphdstudent_value_op';
  $handler->display->display_options['filters']['cap_capphdstudent_value']['expose']['label'] = 'capPhdStudent';
  $handler->display->display_options['filters']['cap_capphdstudent_value']['expose']['operator'] = 'cap_capphdstudent_value_op';
  $handler->display->display_options['filters']['cap_capphdstudent_value']['expose']['identifier'] = 'cap_capphdstudent_value';
  $handler->display->display_options['filters']['cap_capphdstudent_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Field collection item: capMdStudent (cap_capmdstudent) */
  $handler->display->display_options['filters']['cap_capmdstudent_value']['id'] = 'cap_capmdstudent_value';
  $handler->display->display_options['filters']['cap_capmdstudent_value']['table'] = 'field_data_cap_capmdstudent';
  $handler->display->display_options['filters']['cap_capmdstudent_value']['field'] = 'cap_capmdstudent_value';
  $handler->display->display_options['filters']['cap_capmdstudent_value']['relationship'] = 'cap_affiliations_value';
  $handler->display->display_options['filters']['cap_capmdstudent_value']['group'] = 2;
  $handler->display->display_options['filters']['cap_capmdstudent_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['cap_capmdstudent_value']['expose']['operator_id'] = 'cap_capmdstudent_value_op';
  $handler->display->display_options['filters']['cap_capmdstudent_value']['expose']['label'] = 'capMdStudent';
  $handler->display->display_options['filters']['cap_capmdstudent_value']['expose']['operator'] = 'cap_capmdstudent_value_op';
  $handler->display->display_options['filters']['cap_capmdstudent_value']['expose']['identifier'] = 'cap_capmdstudent_value';
  $handler->display->display_options['filters']['cap_capmdstudent_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'stanford-profiles';
  $export['stanford_profiles'] = $view;

  $view = new view();
  $view->name = 'stanford_publications';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford publications';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Stanford publications';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cap_stanford_profile' => 'cap_stanford_profile',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: CAP profile organization (field_cap_profile_organization) */
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['id'] = 'field_cap_profile_organization_tid';
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['table'] = 'field_data_field_cap_profile_organization';
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['field'] = 'field_cap_profile_organization_tid';
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['value'] = '';
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['expose']['operator_id'] = 'field_cap_profile_organization_tid_op';
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['expose']['label'] = 'Organization';
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['expose']['operator'] = 'field_cap_profile_organization_tid_op';
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['expose']['identifier'] = 'field_cap_profile_organization_tid';
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_cap_profile_organization_tid']['vocabulary'] = 'stanford_org_code_hierarchy';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'stanford-publications';
  $export['stanford_publications'] = $view;

  return $export;
}
