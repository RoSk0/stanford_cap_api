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
