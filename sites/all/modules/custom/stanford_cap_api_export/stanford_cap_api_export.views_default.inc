<?php
/**
 * @file
 * stanford_cap_api_export.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_cap_api_export_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'stanford_cap_api_export_profiles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford CAP API: Export profiles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage profiles';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'A list of all CAP profiles currently being stored in the site.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Displaying @start - @end of @total.';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No CAP profiles are being stored in the site. You can <a href="/admin/config/cap/import">add profiles</a> or <a href="/admin/config/cap/group">add groups</a>.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: profileId */
  $handler->display->display_options['fields']['cap_profileid']['id'] = 'cap_profileid';
  $handler->display->display_options['fields']['cap_profileid']['table'] = 'field_data_cap_profileid';
  $handler->display->display_options['fields']['cap_profileid']['field'] = 'cap_profileid';
  $handler->display->display_options['fields']['cap_profileid']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['cap_profileid']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Date last synced */
  $handler->display->display_options['fields']['cap_sync_date']['id'] = 'cap_sync_date';
  $handler->display->display_options['fields']['cap_sync_date']['table'] = 'field_data_cap_sync_date';
  $handler->display->display_options['fields']['cap_sync_date']['field'] = 'cap_sync_date';
  $handler->display->display_options['fields']['cap_sync_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: CAP profile link */
  $handler->display->display_options['fields']['cap_profile_link']['id'] = 'cap_profile_link';
  $handler->display->display_options['fields']['cap_profile_link']['table'] = 'field_data_cap_profile_link';
  $handler->display->display_options['fields']['cap_profile_link']['field'] = 'cap_profile_link';
  $handler->display->display_options['fields']['cap_profile_link']['alter']['text'] = 'View in CAP';
  $handler->display->display_options['fields']['cap_profile_link']['alter']['path'] = '[cap_profile_link-url]';
  $handler->display->display_options['fields']['cap_profile_link']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['cap_profile_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['cap_profile_link']['type'] = 'link_plain';
  /* Field: Content: affiliations */
  $handler->display->display_options['fields']['cap_affiliations']['id'] = 'cap_affiliations';
  $handler->display->display_options['fields']['cap_affiliations']['table'] = 'field_data_cap_affiliations';
  $handler->display->display_options['fields']['cap_affiliations']['field'] = 'cap_affiliations';
  $handler->display->display_options['fields']['cap_affiliations']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['cap_affiliations']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['cap_affiliations']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_affiliations']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_affiliations']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_affiliations']['delta_offset'] = '0';
  /* Field: Content: affiliations (cap_affiliations:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_cap_affiliations';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['separator'] = '';
  /* Field: Content: alternateContact */
  $handler->display->display_options['fields']['cap_alternatecontact']['id'] = 'cap_alternatecontact';
  $handler->display->display_options['fields']['cap_alternatecontact']['table'] = 'field_data_cap_alternatecontact';
  $handler->display->display_options['fields']['cap_alternatecontact']['field'] = 'cap_alternatecontact';
  $handler->display->display_options['fields']['cap_alternatecontact']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_alternatecontact']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_alternatecontact']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_alternatecontact']['delta_offset'] = '0';
  /* Field: Content: alternateContact (cap_alternatecontact:delta) */
  $handler->display->display_options['fields']['delta_1']['id'] = 'delta_1';
  $handler->display->display_options['fields']['delta_1']['table'] = 'field_data_cap_alternatecontact';
  $handler->display->display_options['fields']['delta_1']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_1']['separator'] = '';
  /* Field: Content: bio */
  $handler->display->display_options['fields']['cap_bio']['id'] = 'cap_bio';
  $handler->display->display_options['fields']['cap_bio']['table'] = 'field_data_cap_bio';
  $handler->display->display_options['fields']['cap_bio']['field'] = 'cap_bio';
  /* Field: Content: californiaPhysicianLicense */
  $handler->display->display_options['fields']['cap_californiaphysicianlicense']['id'] = 'cap_californiaphysicianlicense';
  $handler->display->display_options['fields']['cap_californiaphysicianlicense']['table'] = 'field_data_cap_californiaphysicianlicense';
  $handler->display->display_options['fields']['cap_californiaphysicianlicense']['field'] = 'cap_californiaphysicianlicense';
  /* Field: Content: clerkships */
  $handler->display->display_options['fields']['cap_clerkships']['id'] = 'cap_clerkships';
  $handler->display->display_options['fields']['cap_clerkships']['table'] = 'field_data_cap_clerkships';
  $handler->display->display_options['fields']['cap_clerkships']['field'] = 'cap_clerkships';
  $handler->display->display_options['fields']['cap_clerkships']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_clerkships']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_clerkships']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_clerkships']['delta_offset'] = '0';
  /* Field: Content: clerkships (cap_clerkships:delta) */
  $handler->display->display_options['fields']['delta_2']['id'] = 'delta_2';
  $handler->display->display_options['fields']['delta_2']['table'] = 'field_data_cap_clerkships';
  $handler->display->display_options['fields']['delta_2']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_2']['separator'] = '';
  /* Field: Content: clinicalContacts */
  $handler->display->display_options['fields']['cap_clinicalcontacts']['id'] = 'cap_clinicalcontacts';
  $handler->display->display_options['fields']['cap_clinicalcontacts']['table'] = 'field_data_cap_clinicalcontacts';
  $handler->display->display_options['fields']['cap_clinicalcontacts']['field'] = 'cap_clinicalcontacts';
  $handler->display->display_options['fields']['cap_clinicalcontacts']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_clinicalcontacts']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_clinicalcontacts']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_clinicalcontacts']['delta_offset'] = '0';
  /* Field: Content: clinicalContacts (cap_clinicalcontacts:delta) */
  $handler->display->display_options['fields']['delta_3']['id'] = 'delta_3';
  $handler->display->display_options['fields']['delta_3']['table'] = 'field_data_cap_clinicalcontacts';
  $handler->display->display_options['fields']['delta_3']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_3']['separator'] = '';
  /* Field: Content: clinicalFocus */
  $handler->display->display_options['fields']['cap_clinicalfocus']['id'] = 'cap_clinicalfocus';
  $handler->display->display_options['fields']['cap_clinicalfocus']['table'] = 'field_data_cap_clinicalfocus';
  $handler->display->display_options['fields']['cap_clinicalfocus']['field'] = 'cap_clinicalfocus';
  $handler->display->display_options['fields']['cap_clinicalfocus']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_clinicalfocus']['delta_offset'] = '0';
  /* Field: Content: clinicalFocus (cap_clinicalfocus:delta) */
  $handler->display->display_options['fields']['delta_4']['id'] = 'delta_4';
  $handler->display->display_options['fields']['delta_4']['table'] = 'field_data_cap_clinicalfocus';
  $handler->display->display_options['fields']['delta_4']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_4']['separator'] = '';
  /* Field: Content: clinicalInterests */
  $handler->display->display_options['fields']['cap_clinicalinterests']['id'] = 'cap_clinicalinterests';
  $handler->display->display_options['fields']['cap_clinicalinterests']['table'] = 'field_data_cap_clinicalinterests';
  $handler->display->display_options['fields']['cap_clinicalinterests']['field'] = 'cap_clinicalinterests';
  $handler->display->display_options['fields']['cap_clinicalinterests']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_clinicalinterests']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_clinicalinterests']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_clinicalinterests']['delta_offset'] = '0';
  /* Field: Content: clinicalInterests (cap_clinicalinterests:delta) */
  $handler->display->display_options['fields']['delta_5']['id'] = 'delta_5';
  $handler->display->display_options['fields']['delta_5']['table'] = 'field_data_cap_clinicalinterests';
  $handler->display->display_options['fields']['delta_5']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_5']['separator'] = '';
  /* Field: Content: coursesTaught */
  $handler->display->display_options['fields']['cap_coursestaught']['id'] = 'cap_coursestaught';
  $handler->display->display_options['fields']['cap_coursestaught']['table'] = 'field_data_cap_coursestaught';
  $handler->display->display_options['fields']['cap_coursestaught']['field'] = 'cap_coursestaught';
  $handler->display->display_options['fields']['cap_coursestaught']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_coursestaught']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_coursestaught']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_coursestaught']['delta_offset'] = '0';
  /* Field: Content: coursesTaught (cap_coursestaught:delta) */
  $handler->display->display_options['fields']['delta_6']['id'] = 'delta_6';
  $handler->display->display_options['fields']['delta_6']['table'] = 'field_data_cap_coursestaught';
  $handler->display->display_options['fields']['delta_6']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_6']['separator'] = '';
  /* Field: Content: currentResearchInterests */
  $handler->display->display_options['fields']['cap_currentresearchinterests']['id'] = 'cap_currentresearchinterests';
  $handler->display->display_options['fields']['cap_currentresearchinterests']['table'] = 'field_data_cap_currentresearchinterests';
  $handler->display->display_options['fields']['cap_currentresearchinterests']['field'] = 'cap_currentresearchinterests';
  $handler->display->display_options['fields']['cap_currentresearchinterests']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_currentresearchinterests']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_currentresearchinterests']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_currentresearchinterests']['delta_offset'] = '0';
  /* Field: Content: currentResearchInterests (cap_currentresearchinterests:delta) */
  $handler->display->display_options['fields']['delta_7']['id'] = 'delta_7';
  $handler->display->display_options['fields']['delta_7']['table'] = 'field_data_cap_currentresearchinterests';
  $handler->display->display_options['fields']['delta_7']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_7']['separator'] = '';
  /* Field: Content: displayName */
  $handler->display->display_options['fields']['cap_displayname']['id'] = 'cap_displayname';
  $handler->display->display_options['fields']['cap_displayname']['table'] = 'field_data_cap_displayname';
  $handler->display->display_options['fields']['cap_displayname']['field'] = 'cap_displayname';
  /* Field: Content: documents */
  $handler->display->display_options['fields']['cap_documents']['id'] = 'cap_documents';
  $handler->display->display_options['fields']['cap_documents']['table'] = 'field_data_cap_documents';
  $handler->display->display_options['fields']['cap_documents']['field'] = 'cap_documents';
  $handler->display->display_options['fields']['cap_documents']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_documents']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_documents']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_documents']['delta_offset'] = '0';
  /* Field: Content: documents (cap_documents:delta) */
  $handler->display->display_options['fields']['delta_8']['id'] = 'delta_8';
  $handler->display->display_options['fields']['delta_8']['table'] = 'field_data_cap_documents';
  $handler->display->display_options['fields']['delta_8']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_8']['separator'] = '';
  /* Field: Content: education */
  $handler->display->display_options['fields']['cap_education']['id'] = 'cap_education';
  $handler->display->display_options['fields']['cap_education']['table'] = 'field_data_cap_education';
  $handler->display->display_options['fields']['cap_education']['field'] = 'cap_education';
  $handler->display->display_options['fields']['cap_education']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_education']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_education']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_education']['delta_offset'] = '0';
  /* Field: Content: education (cap_education:delta) */
  $handler->display->display_options['fields']['delta_9']['id'] = 'delta_9';
  $handler->display->display_options['fields']['delta_9']['table'] = 'field_data_cap_education';
  $handler->display->display_options['fields']['delta_9']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_9']['separator'] = '';
  /* Field: Content: graduateAndFellowshipPrograms */
  $handler->display->display_options['fields']['cap_graduateandfellowshipprogram']['id'] = 'cap_graduateandfellowshipprogram';
  $handler->display->display_options['fields']['cap_graduateandfellowshipprogram']['table'] = 'field_data_cap_graduateandfellowshipprogram';
  $handler->display->display_options['fields']['cap_graduateandfellowshipprogram']['field'] = 'cap_graduateandfellowshipprogram';
  $handler->display->display_options['fields']['cap_graduateandfellowshipprogram']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_graduateandfellowshipprogram']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_graduateandfellowshipprogram']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_graduateandfellowshipprogram']['delta_offset'] = '0';
  /* Field: Content: graduateAndFellowshipPrograms (cap_graduateandfellowshipprogram:delta) */
  $handler->display->display_options['fields']['delta_10']['id'] = 'delta_10';
  $handler->display->display_options['fields']['delta_10']['table'] = 'field_data_cap_graduateandfellowshipprogram';
  $handler->display->display_options['fields']['delta_10']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_10']['separator'] = '';
  /* Field: Content: honorsAndAwards */
  $handler->display->display_options['fields']['cap_honorsandawards']['id'] = 'cap_honorsandawards';
  $handler->display->display_options['fields']['cap_honorsandawards']['table'] = 'field_data_cap_honorsandawards';
  $handler->display->display_options['fields']['cap_honorsandawards']['field'] = 'cap_honorsandawards';
  $handler->display->display_options['fields']['cap_honorsandawards']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_honorsandawards']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_honorsandawards']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_honorsandawards']['delta_offset'] = '0';
  /* Field: Content: honorsAndAwards (cap_honorsandawards:delta) */
  $handler->display->display_options['fields']['delta_11']['id'] = 'delta_11';
  $handler->display->display_options['fields']['delta_11']['table'] = 'field_data_cap_honorsandawards';
  $handler->display->display_options['fields']['delta_11']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_11']['separator'] = '';
  /* Field: Content: internetLinks */
  $handler->display->display_options['fields']['cap_internetlinks']['id'] = 'cap_internetlinks';
  $handler->display->display_options['fields']['cap_internetlinks']['table'] = 'field_data_cap_internetlinks';
  $handler->display->display_options['fields']['cap_internetlinks']['field'] = 'cap_internetlinks';
  $handler->display->display_options['fields']['cap_internetlinks']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_internetlinks']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_internetlinks']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_internetlinks']['delta_offset'] = '0';
  /* Field: Content: internetLinks (cap_internetlinks:delta) */
  $handler->display->display_options['fields']['delta_12']['id'] = 'delta_12';
  $handler->display->display_options['fields']['delta_12']['table'] = 'field_data_cap_internetlinks';
  $handler->display->display_options['fields']['delta_12']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_12']['separator'] = '';
  /* Field: Content: keywords */
  $handler->display->display_options['fields']['cap_keywords']['id'] = 'cap_keywords';
  $handler->display->display_options['fields']['cap_keywords']['table'] = 'field_data_cap_keywords';
  $handler->display->display_options['fields']['cap_keywords']['field'] = 'cap_keywords';
  $handler->display->display_options['fields']['cap_keywords']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_keywords']['delta_offset'] = '0';
  /* Field: Content: keywords (cap_keywords:delta) */
  $handler->display->display_options['fields']['delta_13']['id'] = 'delta_13';
  $handler->display->display_options['fields']['delta_13']['table'] = 'field_data_cap_keywords';
  $handler->display->display_options['fields']['delta_13']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_13']['separator'] = '';
  /* Field: Content: labAffiliations */
  $handler->display->display_options['fields']['cap_labaffiliations']['id'] = 'cap_labaffiliations';
  $handler->display->display_options['fields']['cap_labaffiliations']['table'] = 'field_data_cap_labaffiliations';
  $handler->display->display_options['fields']['cap_labaffiliations']['field'] = 'cap_labaffiliations';
  $handler->display->display_options['fields']['cap_labaffiliations']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_labaffiliations']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_labaffiliations']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_labaffiliations']['delta_offset'] = '0';
  /* Field: Content: labAffiliations (cap_labaffiliations:delta) */
  $handler->display->display_options['fields']['delta_14']['id'] = 'delta_14';
  $handler->display->display_options['fields']['delta_14']['table'] = 'field_data_cap_labaffiliations';
  $handler->display->display_options['fields']['delta_14']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_14']['separator'] = '';
  /* Field: Content: lastModified */
  $handler->display->display_options['fields']['cap_lastmodified']['id'] = 'cap_lastmodified';
  $handler->display->display_options['fields']['cap_lastmodified']['table'] = 'field_data_cap_lastmodified';
  $handler->display->display_options['fields']['cap_lastmodified']['field'] = 'cap_lastmodified';
  $handler->display->display_options['fields']['cap_lastmodified']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: longTitle */
  $handler->display->display_options['fields']['cap_longtitle']['id'] = 'cap_longtitle';
  $handler->display->display_options['fields']['cap_longtitle']['table'] = 'field_data_cap_longtitle';
  $handler->display->display_options['fields']['cap_longtitle']['field'] = 'cap_longtitle';
  $handler->display->display_options['fields']['cap_longtitle']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_longtitle']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_longtitle']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_longtitle']['delta_offset'] = '0';
  /* Field: Content: longTitle (cap_longtitle:delta) */
  $handler->display->display_options['fields']['delta_15']['id'] = 'delta_15';
  $handler->display->display_options['fields']['delta_15']['table'] = 'field_data_cap_longtitle';
  $handler->display->display_options['fields']['delta_15']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_15']['separator'] = '';
  /* Field: Content: membershipOrganizations */
  $handler->display->display_options['fields']['cap_membershiporganizations']['id'] = 'cap_membershiporganizations';
  $handler->display->display_options['fields']['cap_membershiporganizations']['table'] = 'field_data_cap_membershiporganizations';
  $handler->display->display_options['fields']['cap_membershiporganizations']['field'] = 'cap_membershiporganizations';
  $handler->display->display_options['fields']['cap_membershiporganizations']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_membershiporganizations']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_membershiporganizations']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_membershiporganizations']['delta_offset'] = '0';
  /* Field: Content: membershipOrganizations (cap_membershiporganizations:delta) */
  $handler->display->display_options['fields']['delta_16']['id'] = 'delta_16';
  $handler->display->display_options['fields']['delta_16']['table'] = 'field_data_cap_membershiporganizations';
  $handler->display->display_options['fields']['delta_16']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_16']['separator'] = '';
  /* Field: Content: meta */
  $handler->display->display_options['fields']['cap_meta']['id'] = 'cap_meta';
  $handler->display->display_options['fields']['cap_meta']['table'] = 'field_data_cap_meta';
  $handler->display->display_options['fields']['cap_meta']['field'] = 'cap_meta';
  $handler->display->display_options['fields']['cap_meta']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_meta']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_meta']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_meta']['delta_offset'] = '0';
  /* Field: Content: meta (cap_meta:delta) */
  $handler->display->display_options['fields']['delta_17']['id'] = 'delta_17';
  $handler->display->display_options['fields']['delta_17']['table'] = 'field_data_cap_meta';
  $handler->display->display_options['fields']['delta_17']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_17']['separator'] = '';
  /* Field: Content: names */
  $handler->display->display_options['fields']['cap_names']['id'] = 'cap_names';
  $handler->display->display_options['fields']['cap_names']['table'] = 'field_data_cap_names';
  $handler->display->display_options['fields']['cap_names']['field'] = 'cap_names';
  $handler->display->display_options['fields']['cap_names']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_names']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_names']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_names']['delta_offset'] = '0';
  /* Field: Content: names (cap_names:delta) */
  $handler->display->display_options['fields']['delta_18']['id'] = 'delta_18';
  $handler->display->display_options['fields']['delta_18']['table'] = 'field_data_cap_names';
  $handler->display->display_options['fields']['delta_18']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_18']['separator'] = '';
  /* Field: Content: personalInterests */
  $handler->display->display_options['fields']['cap_personalinterests']['id'] = 'cap_personalinterests';
  $handler->display->display_options['fields']['cap_personalinterests']['table'] = 'field_data_cap_personalinterests';
  $handler->display->display_options['fields']['cap_personalinterests']['field'] = 'cap_personalinterests';
  /* Field: Content: presentations */
  $handler->display->display_options['fields']['cap_presentations']['id'] = 'cap_presentations';
  $handler->display->display_options['fields']['cap_presentations']['table'] = 'field_data_cap_presentations';
  $handler->display->display_options['fields']['cap_presentations']['field'] = 'cap_presentations';
  $handler->display->display_options['fields']['cap_presentations']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_presentations']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_presentations']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_presentations']['delta_offset'] = '0';
  /* Field: Content: presentations (cap_presentations:delta) */
  $handler->display->display_options['fields']['delta_19']['id'] = 'delta_19';
  $handler->display->display_options['fields']['delta_19']['table'] = 'field_data_cap_presentations';
  $handler->display->display_options['fields']['delta_19']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_19']['separator'] = '';
  /* Field: Content: primaryContact */
  $handler->display->display_options['fields']['cap_primarycontact']['id'] = 'cap_primarycontact';
  $handler->display->display_options['fields']['cap_primarycontact']['table'] = 'field_data_cap_primarycontact';
  $handler->display->display_options['fields']['cap_primarycontact']['field'] = 'cap_primarycontact';
  $handler->display->display_options['fields']['cap_primarycontact']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_primarycontact']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_primarycontact']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_primarycontact']['delta_offset'] = '0';
  /* Field: Content: primaryContact (cap_primarycontact:delta) */
  $handler->display->display_options['fields']['delta_20']['id'] = 'delta_20';
  $handler->display->display_options['fields']['delta_20']['table'] = 'field_data_cap_primarycontact';
  $handler->display->display_options['fields']['delta_20']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_20']['separator'] = '';
  /* Field: Content: profilePhotos */
  $handler->display->display_options['fields']['cap_profilephotos']['id'] = 'cap_profilephotos';
  $handler->display->display_options['fields']['cap_profilephotos']['table'] = 'field_data_cap_profilephotos';
  $handler->display->display_options['fields']['cap_profilephotos']['field'] = 'cap_profilephotos';
  $handler->display->display_options['fields']['cap_profilephotos']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_profilephotos']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_profilephotos']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_profilephotos']['delta_offset'] = '0';
  /* Field: Content: profilePhotos (cap_profilephotos:delta) */
  $handler->display->display_options['fields']['delta_21']['id'] = 'delta_21';
  $handler->display->display_options['fields']['delta_21']['table'] = 'field_data_cap_profilephotos';
  $handler->display->display_options['fields']['delta_21']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_21']['separator'] = '';
  /* Field: Content: publications */
  $handler->display->display_options['fields']['cap_publications']['id'] = 'cap_publications';
  $handler->display->display_options['fields']['cap_publications']['table'] = 'field_data_cap_publications';
  $handler->display->display_options['fields']['cap_publications']['field'] = 'cap_publications';
  $handler->display->display_options['fields']['cap_publications']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_publications']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_publications']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_publications']['delta_offset'] = '0';
  /* Field: Content: publications (cap_publications:delta) */
  $handler->display->display_options['fields']['delta_22']['id'] = 'delta_22';
  $handler->display->display_options['fields']['delta_22']['table'] = 'field_data_cap_publications';
  $handler->display->display_options['fields']['delta_22']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_22']['separator'] = '';
  /* Field: Content: publicationTags */
  $handler->display->display_options['fields']['cap_publicationtags']['id'] = 'cap_publicationtags';
  $handler->display->display_options['fields']['cap_publicationtags']['table'] = 'field_data_cap_publicationtags';
  $handler->display->display_options['fields']['cap_publicationtags']['field'] = 'cap_publicationtags';
  $handler->display->display_options['fields']['cap_publicationtags']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_publicationtags']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_publicationtags']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_publicationtags']['delta_offset'] = '0';
  /* Field: Content: publicationTags (cap_publicationtags:delta) */
  $handler->display->display_options['fields']['delta_23']['id'] = 'delta_23';
  $handler->display->display_options['fields']['delta_23']['table'] = 'field_data_cap_publicationtags';
  $handler->display->display_options['fields']['delta_23']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_23']['separator'] = '';
  /* Field: Content: researchProjects */
  $handler->display->display_options['fields']['cap_researchprojects']['id'] = 'cap_researchprojects';
  $handler->display->display_options['fields']['cap_researchprojects']['table'] = 'field_data_cap_researchprojects';
  $handler->display->display_options['fields']['cap_researchprojects']['field'] = 'cap_researchprojects';
  $handler->display->display_options['fields']['cap_researchprojects']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_researchprojects']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_researchprojects']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_researchprojects']['delta_offset'] = '0';
  /* Field: Content: researchProjects (cap_researchprojects:delta) */
  $handler->display->display_options['fields']['delta_24']['id'] = 'delta_24';
  $handler->display->display_options['fields']['delta_24']['table'] = 'field_data_cap_researchprojects';
  $handler->display->display_options['fields']['delta_24']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_24']['separator'] = '';
  /* Field: Content: serviceWork */
  $handler->display->display_options['fields']['cap_servicework']['id'] = 'cap_servicework';
  $handler->display->display_options['fields']['cap_servicework']['table'] = 'field_data_cap_servicework';
  $handler->display->display_options['fields']['cap_servicework']['field'] = 'cap_servicework';
  $handler->display->display_options['fields']['cap_servicework']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_servicework']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_servicework']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_servicework']['delta_offset'] = '0';
  /* Field: Content: serviceWork (cap_servicework:delta) */
  $handler->display->display_options['fields']['delta_25']['id'] = 'delta_25';
  $handler->display->display_options['fields']['delta_25']['table'] = 'field_data_cap_servicework';
  $handler->display->display_options['fields']['delta_25']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_25']['separator'] = '';
  /* Field: Content: shortTitle */
  $handler->display->display_options['fields']['cap_shorttitle']['id'] = 'cap_shorttitle';
  $handler->display->display_options['fields']['cap_shorttitle']['table'] = 'field_data_cap_shorttitle';
  $handler->display->display_options['fields']['cap_shorttitle']['field'] = 'cap_shorttitle';
  $handler->display->display_options['fields']['cap_shorttitle']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_shorttitle']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_shorttitle']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_shorttitle']['delta_offset'] = '0';
  /* Field: Content: shortTitle (cap_shorttitle:delta) */
  $handler->display->display_options['fields']['delta_26']['id'] = 'delta_26';
  $handler->display->display_options['fields']['delta_26']['table'] = 'field_data_cap_shorttitle';
  $handler->display->display_options['fields']['delta_26']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_26']['separator'] = '';
  /* Field: Content: showFeaturedPublicationsFirst */
  $handler->display->display_options['fields']['cap_showfeaturedpublicationsfirs']['id'] = 'cap_showfeaturedpublicationsfirs';
  $handler->display->display_options['fields']['cap_showfeaturedpublicationsfirs']['table'] = 'field_data_cap_showfeaturedpublicationsfirs';
  $handler->display->display_options['fields']['cap_showfeaturedpublicationsfirs']['field'] = 'cap_showfeaturedpublicationsfirs';
  /* Field: Content: similarProfiles */
  $handler->display->display_options['fields']['cap_similarprofiles']['id'] = 'cap_similarprofiles';
  $handler->display->display_options['fields']['cap_similarprofiles']['table'] = 'field_data_cap_similarprofiles';
  $handler->display->display_options['fields']['cap_similarprofiles']['field'] = 'cap_similarprofiles';
  $handler->display->display_options['fields']['cap_similarprofiles']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_similarprofiles']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_similarprofiles']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_similarprofiles']['delta_offset'] = '0';
  /* Field: Content: similarProfiles (cap_similarprofiles:delta) */
  $handler->display->display_options['fields']['delta_27']['id'] = 'delta_27';
  $handler->display->display_options['fields']['delta_27']['table'] = 'field_data_cap_similarprofiles';
  $handler->display->display_options['fields']['delta_27']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_27']['separator'] = '';
  /* Field: Content: stanfordAdvisors */
  $handler->display->display_options['fields']['cap_stanfordadvisors']['id'] = 'cap_stanfordadvisors';
  $handler->display->display_options['fields']['cap_stanfordadvisors']['table'] = 'field_data_cap_stanfordadvisors';
  $handler->display->display_options['fields']['cap_stanfordadvisors']['field'] = 'cap_stanfordadvisors';
  $handler->display->display_options['fields']['cap_stanfordadvisors']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_stanfordadvisors']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_stanfordadvisors']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_stanfordadvisors']['delta_offset'] = '0';
  /* Field: Content: stanfordAdvisors (cap_stanfordadvisors:delta) */
  $handler->display->display_options['fields']['delta_28']['id'] = 'delta_28';
  $handler->display->display_options['fields']['delta_28']['table'] = 'field_data_cap_stanfordadvisors';
  $handler->display->display_options['fields']['delta_28']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_28']['separator'] = '';
  /* Field: Content: test */
  $handler->display->display_options['fields']['field_test']['id'] = 'field_test';
  $handler->display->display_options['fields']['field_test']['table'] = 'field_data_field_test';
  $handler->display->display_options['fields']['field_test']['field'] = 'field_test';
  /* Field: Content: titles */
  $handler->display->display_options['fields']['cap_titles']['id'] = 'cap_titles';
  $handler->display->display_options['fields']['cap_titles']['table'] = 'field_data_cap_titles';
  $handler->display->display_options['fields']['cap_titles']['field'] = 'cap_titles';
  $handler->display->display_options['fields']['cap_titles']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_titles']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_titles']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_titles']['delta_offset'] = '0';
  /* Field: Content: workExperience */
  $handler->display->display_options['fields']['cap_workexperience']['id'] = 'cap_workexperience';
  $handler->display->display_options['fields']['cap_workexperience']['table'] = 'field_data_cap_workexperience';
  $handler->display->display_options['fields']['cap_workexperience']['field'] = 'cap_workexperience';
  $handler->display->display_options['fields']['cap_workexperience']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_workexperience']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_workexperience']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['cap_workexperience']['delta_offset'] = '0';
  /* Field: Content: workExperience (cap_workexperience:delta) */
  $handler->display->display_options['fields']['delta_31']['id'] = 'delta_31';
  $handler->display->display_options['fields']['delta_31']['table'] = 'field_data_cap_workexperience';
  $handler->display->display_options['fields']['delta_31']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_31']['separator'] = '';
  /* Field: Field: alias */
  $handler->display->display_options['fields']['cap_alias']['id'] = 'cap_alias';
  $handler->display->display_options['fields']['cap_alias']['table'] = 'field_data_cap_alias';
  $handler->display->display_options['fields']['cap_alias']['field'] = 'cap_alias';
  /* Field: Content: Tags (field_tags:delta) */
  $handler->display->display_options['fields']['delta_29']['id'] = 'delta_29';
  $handler->display->display_options['fields']['delta_29']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['delta_29']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_29']['separator'] = '';
  /* Field: Content: titles (cap_titles:delta) */
  $handler->display->display_options['fields']['delta_30']['id'] = 'delta_30';
  $handler->display->display_options['fields']['delta_30']['table'] = 'field_data_cap_titles';
  $handler->display->display_options['fields']['delta_30']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_30']['separator'] = '';
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
    'cap_faculty_profile' => 'cap_faculty_profile',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 1;
  $handler->display->display_options['style_options']['replace_newlines'] = 1;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'profiles_export.csv';
  $export['stanford_cap_api_export_profiles'] = $view;

  $view = new view();
  $view->name = 'stanford_cap_api_export_projects';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford CAP API: Export projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage profiles';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'A list of all CAP profiles currently being stored in the site.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Displaying @start - @end of @total.';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No CAP profiles are being stored in the site. You can <a href="/admin/config/cap/import">add profiles</a> or <a href="/admin/config/cap/group">add groups</a>.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: researchProjects (cap_researchprojects) */
  $handler->display->display_options['relationships']['cap_researchprojects_value']['id'] = 'cap_researchprojects_value';
  $handler->display->display_options['relationships']['cap_researchprojects_value']['table'] = 'field_data_cap_researchprojects';
  $handler->display->display_options['relationships']['cap_researchprojects_value']['field'] = 'cap_researchprojects_value';
  $handler->display->display_options['relationships']['cap_researchprojects_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['cap_researchprojects_value']['delta'] = '-1';
  /* Relationship: Field collection item: projectType (cap_projecttype) */
  $handler->display->display_options['relationships']['cap_projecttype_value']['id'] = 'cap_projecttype_value';
  $handler->display->display_options['relationships']['cap_projecttype_value']['table'] = 'field_data_cap_projecttype';
  $handler->display->display_options['relationships']['cap_projecttype_value']['field'] = 'cap_projecttype_value';
  $handler->display->display_options['relationships']['cap_projecttype_value']['relationship'] = 'cap_researchprojects_value';
  $handler->display->display_options['relationships']['cap_projecttype_value']['delta'] = '-1';
  /* Relationship: Field collection item: collaborators (cap_collaborators) */
  $handler->display->display_options['relationships']['cap_collaborators_value']['id'] = 'cap_collaborators_value';
  $handler->display->display_options['relationships']['cap_collaborators_value']['table'] = 'field_data_cap_collaborators';
  $handler->display->display_options['relationships']['cap_collaborators_value']['field'] = 'cap_collaborators_value';
  $handler->display->display_options['relationships']['cap_collaborators_value']['relationship'] = 'cap_researchprojects_value';
  $handler->display->display_options['relationships']['cap_collaborators_value']['delta'] = '-1';
  /* Relationship: Field collection item: media (cap_media) */
  $handler->display->display_options['relationships']['cap_media_value']['id'] = 'cap_media_value';
  $handler->display->display_options['relationships']['cap_media_value']['table'] = 'field_data_cap_media';
  $handler->display->display_options['relationships']['cap_media_value']['field'] = 'cap_media_value';
  $handler->display->display_options['relationships']['cap_media_value']['relationship'] = 'cap_researchprojects_value';
  $handler->display->display_options['relationships']['cap_media_value']['delta'] = '-1';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: profileId */
  $handler->display->display_options['fields']['cap_profileid']['id'] = 'cap_profileid';
  $handler->display->display_options['fields']['cap_profileid']['table'] = 'field_data_cap_profileid';
  $handler->display->display_options['fields']['cap_profileid']['field'] = 'cap_profileid';
  $handler->display->display_options['fields']['cap_profileid']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['cap_profileid']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Date last synced */
  $handler->display->display_options['fields']['cap_sync_date']['id'] = 'cap_sync_date';
  $handler->display->display_options['fields']['cap_sync_date']['table'] = 'field_data_cap_sync_date';
  $handler->display->display_options['fields']['cap_sync_date']['field'] = 'cap_sync_date';
  $handler->display->display_options['fields']['cap_sync_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: CAP profile link */
  $handler->display->display_options['fields']['cap_profile_link']['id'] = 'cap_profile_link';
  $handler->display->display_options['fields']['cap_profile_link']['table'] = 'field_data_cap_profile_link';
  $handler->display->display_options['fields']['cap_profile_link']['field'] = 'cap_profile_link';
  $handler->display->display_options['fields']['cap_profile_link']['alter']['text'] = 'View in CAP';
  $handler->display->display_options['fields']['cap_profile_link']['alter']['path'] = '[cap_profile_link-url]';
  $handler->display->display_options['fields']['cap_profile_link']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['cap_profile_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['cap_profile_link']['type'] = 'link_plain';
  /* Field: Field collection item: label */
  $handler->display->display_options['fields']['cap_label']['id'] = 'cap_label';
  $handler->display->display_options['fields']['cap_label']['table'] = 'field_data_cap_label';
  $handler->display->display_options['fields']['cap_label']['field'] = 'cap_label';
  $handler->display->display_options['fields']['cap_label']['relationship'] = 'cap_researchprojects_value';
  $handler->display->display_options['fields']['cap_label']['label'] = 'Research project label';
  $handler->display->display_options['fields']['cap_label']['type'] = 'text_plain';
  /* Field: Field collection item: title */
  $handler->display->display_options['fields']['cap_title']['id'] = 'cap_title';
  $handler->display->display_options['fields']['cap_title']['table'] = 'field_data_cap_title';
  $handler->display->display_options['fields']['cap_title']['field'] = 'cap_title';
  $handler->display->display_options['fields']['cap_title']['relationship'] = 'cap_researchprojects_value';
  $handler->display->display_options['fields']['cap_title']['label'] = 'Research project title';
  $handler->display->display_options['fields']['cap_title']['type'] = 'text_plain';
  /* Field: Field collection item: location */
  $handler->display->display_options['fields']['cap_location']['id'] = 'cap_location';
  $handler->display->display_options['fields']['cap_location']['table'] = 'field_data_cap_location';
  $handler->display->display_options['fields']['cap_location']['field'] = 'cap_location';
  $handler->display->display_options['fields']['cap_location']['relationship'] = 'cap_researchprojects_value';
  $handler->display->display_options['fields']['cap_location']['label'] = 'Research project location';
  $handler->display->display_options['fields']['cap_location']['type'] = 'text_plain';
  /* Field: Field collection item: description */
  $handler->display->display_options['fields']['cap_description']['id'] = 'cap_description';
  $handler->display->display_options['fields']['cap_description']['table'] = 'field_data_cap_description';
  $handler->display->display_options['fields']['cap_description']['field'] = 'cap_description';
  $handler->display->display_options['fields']['cap_description']['relationship'] = 'cap_researchprojects_value';
  $handler->display->display_options['fields']['cap_description']['label'] = 'Research project description';
  $handler->display->display_options['fields']['cap_description']['type'] = 'text_plain';
  /* Field: Field collection item: startDate */
  $handler->display->display_options['fields']['cap_startdate']['id'] = 'cap_startdate';
  $handler->display->display_options['fields']['cap_startdate']['table'] = 'field_data_cap_startdate';
  $handler->display->display_options['fields']['cap_startdate']['field'] = 'cap_startdate';
  $handler->display->display_options['fields']['cap_startdate']['relationship'] = 'cap_researchprojects_value';
  $handler->display->display_options['fields']['cap_startdate']['label'] = 'Research project startDate';
  $handler->display->display_options['fields']['cap_startdate']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field collection item: endDate */
  $handler->display->display_options['fields']['cap_enddate']['id'] = 'cap_enddate';
  $handler->display->display_options['fields']['cap_enddate']['table'] = 'field_data_cap_enddate';
  $handler->display->display_options['fields']['cap_enddate']['field'] = 'cap_enddate';
  $handler->display->display_options['fields']['cap_enddate']['relationship'] = 'cap_researchprojects_value';
  $handler->display->display_options['fields']['cap_enddate']['label'] = 'Research project endDate';
  $handler->display->display_options['fields']['cap_enddate']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field collection item: institution */
  $handler->display->display_options['fields']['cap_institution']['id'] = 'cap_institution';
  $handler->display->display_options['fields']['cap_institution']['table'] = 'field_data_cap_institution';
  $handler->display->display_options['fields']['cap_institution']['field'] = 'cap_institution';
  $handler->display->display_options['fields']['cap_institution']['relationship'] = 'cap_researchprojects_value';
  $handler->display->display_options['fields']['cap_institution']['label'] = 'Research project institution';
  $handler->display->display_options['fields']['cap_institution']['type'] = 'text_plain';
  /* Field: Content: researchProjects (cap_researchprojects:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_cap_researchprojects';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['label'] = 'Research project delta';
  $handler->display->display_options['fields']['delta']['separator'] = '';
  /* Field: Field collection item: key */
  $handler->display->display_options['fields']['cap_key']['id'] = 'cap_key';
  $handler->display->display_options['fields']['cap_key']['table'] = 'field_data_cap_key';
  $handler->display->display_options['fields']['cap_key']['field'] = 'cap_key';
  $handler->display->display_options['fields']['cap_key']['relationship'] = 'cap_projecttype_value';
  $handler->display->display_options['fields']['cap_key']['label'] = 'Research project type key';
  $handler->display->display_options['fields']['cap_key']['type'] = 'text_plain';
  /* Field: Field collection item: value */
  $handler->display->display_options['fields']['cap_value']['id'] = 'cap_value';
  $handler->display->display_options['fields']['cap_value']['table'] = 'field_data_cap_value';
  $handler->display->display_options['fields']['cap_value']['field'] = 'cap_value';
  $handler->display->display_options['fields']['cap_value']['relationship'] = 'cap_projecttype_value';
  $handler->display->display_options['fields']['cap_value']['label'] = 'Research project type value';
  /* Field: Field collection item: projectType (cap_projecttype:delta) */
  $handler->display->display_options['fields']['delta_1']['id'] = 'delta_1';
  $handler->display->display_options['fields']['delta_1']['table'] = 'field_data_cap_projecttype';
  $handler->display->display_options['fields']['delta_1']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_1']['relationship'] = 'cap_researchprojects_value';
  $handler->display->display_options['fields']['delta_1']['label'] = 'Research project type delta';
  $handler->display->display_options['fields']['delta_1']['separator'] = '';
  /* Field: Field: alias */
  $handler->display->display_options['fields']['cap_alias']['id'] = 'cap_alias';
  $handler->display->display_options['fields']['cap_alias']['table'] = 'field_data_cap_alias';
  $handler->display->display_options['fields']['cap_alias']['field'] = 'cap_alias';
  $handler->display->display_options['fields']['cap_alias']['relationship'] = 'cap_collaborators_value';
  $handler->display->display_options['fields']['cap_alias']['label'] = 'Research project collaborators alias';
  $handler->display->display_options['fields']['cap_alias']['type'] = 'text_plain';
  /* Field: Field collection item: firstName */
  $handler->display->display_options['fields']['cap_firstname']['id'] = 'cap_firstname';
  $handler->display->display_options['fields']['cap_firstname']['table'] = 'field_data_cap_firstname';
  $handler->display->display_options['fields']['cap_firstname']['field'] = 'cap_firstname';
  $handler->display->display_options['fields']['cap_firstname']['relationship'] = 'cap_collaborators_value';
  $handler->display->display_options['fields']['cap_firstname']['label'] = 'Research project collaborators firstName';
  $handler->display->display_options['fields']['cap_firstname']['type'] = 'text_plain';
  /* Field: Field collection item: lastName */
  $handler->display->display_options['fields']['cap_lastname']['id'] = 'cap_lastname';
  $handler->display->display_options['fields']['cap_lastname']['table'] = 'field_data_cap_lastname';
  $handler->display->display_options['fields']['cap_lastname']['field'] = 'cap_lastname';
  $handler->display->display_options['fields']['cap_lastname']['relationship'] = 'cap_collaborators_value';
  $handler->display->display_options['fields']['cap_lastname']['label'] = 'Research project collaborators lastName';
  $handler->display->display_options['fields']['cap_lastname']['type'] = 'text_plain';
  /* Field: Field collection item: label */
  $handler->display->display_options['fields']['cap_label_1']['id'] = 'cap_label_1';
  $handler->display->display_options['fields']['cap_label_1']['table'] = 'field_data_cap_label';
  $handler->display->display_options['fields']['cap_label_1']['field'] = 'cap_label';
  $handler->display->display_options['fields']['cap_label_1']['relationship'] = 'cap_collaborators_value';
  $handler->display->display_options['fields']['cap_label_1']['label'] = 'Research project collaborators label';
  $handler->display->display_options['fields']['cap_label_1']['type'] = 'text_plain';
  /* Field: Field collection item: principalInvestigator */
  $handler->display->display_options['fields']['cap_principalinvestigator']['id'] = 'cap_principalinvestigator';
  $handler->display->display_options['fields']['cap_principalinvestigator']['table'] = 'field_data_cap_principalinvestigator';
  $handler->display->display_options['fields']['cap_principalinvestigator']['field'] = 'cap_principalinvestigator';
  $handler->display->display_options['fields']['cap_principalinvestigator']['relationship'] = 'cap_collaborators_value';
  $handler->display->display_options['fields']['cap_principalinvestigator']['label'] = 'Research project collaborators principalInvestigator';
  /* Field: Field: profileId */
  $handler->display->display_options['fields']['cap_profileid_1']['id'] = 'cap_profileid_1';
  $handler->display->display_options['fields']['cap_profileid_1']['table'] = 'field_data_cap_profileid';
  $handler->display->display_options['fields']['cap_profileid_1']['field'] = 'cap_profileid';
  $handler->display->display_options['fields']['cap_profileid_1']['relationship'] = 'cap_collaborators_value';
  $handler->display->display_options['fields']['cap_profileid_1']['label'] = 'Research project collaborators profileId';
  $handler->display->display_options['fields']['cap_profileid_1']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: title */
  $handler->display->display_options['fields']['cap_title_1']['id'] = 'cap_title_1';
  $handler->display->display_options['fields']['cap_title_1']['table'] = 'field_data_cap_title';
  $handler->display->display_options['fields']['cap_title_1']['field'] = 'cap_title';
  $handler->display->display_options['fields']['cap_title_1']['relationship'] = 'cap_collaborators_value';
  $handler->display->display_options['fields']['cap_title_1']['label'] = 'Research project collaborators title';
  $handler->display->display_options['fields']['cap_title_1']['type'] = 'text_plain';
  /* Field: Field collection item: collaborators (cap_collaborators:delta) */
  $handler->display->display_options['fields']['delta_2']['id'] = 'delta_2';
  $handler->display->display_options['fields']['delta_2']['table'] = 'field_data_cap_collaborators';
  $handler->display->display_options['fields']['delta_2']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_2']['relationship'] = 'cap_researchprojects_value';
  $handler->display->display_options['fields']['delta_2']['label'] = 'Research project collaborators delta';
  $handler->display->display_options['fields']['delta_2']['separator'] = '';
  /* Field: Field collection item: label */
  $handler->display->display_options['fields']['cap_label_2']['id'] = 'cap_label_2';
  $handler->display->display_options['fields']['cap_label_2']['table'] = 'field_data_cap_label';
  $handler->display->display_options['fields']['cap_label_2']['field'] = 'cap_label';
  $handler->display->display_options['fields']['cap_label_2']['relationship'] = 'cap_media_value';
  $handler->display->display_options['fields']['cap_label_2']['label'] = 'Research project media label';
  $handler->display->display_options['fields']['cap_label_2']['type'] = 'text_plain';
  /* Field: Field collection item: type */
  $handler->display->display_options['fields']['cap_type']['id'] = 'cap_type';
  $handler->display->display_options['fields']['cap_type']['table'] = 'field_data_cap_type';
  $handler->display->display_options['fields']['cap_type']['field'] = 'cap_type';
  $handler->display->display_options['fields']['cap_type']['relationship'] = 'cap_media_value';
  $handler->display->display_options['fields']['cap_type']['label'] = 'Research project media type';
  $handler->display->display_options['fields']['cap_type']['type'] = 'text_plain';
  /* Field: Field collection item: url */
  $handler->display->display_options['fields']['cap_url']['id'] = 'cap_url';
  $handler->display->display_options['fields']['cap_url']['table'] = 'field_data_cap_url';
  $handler->display->display_options['fields']['cap_url']['field'] = 'cap_url';
  $handler->display->display_options['fields']['cap_url']['relationship'] = 'cap_media_value';
  $handler->display->display_options['fields']['cap_url']['label'] = 'Research project media url';
  $handler->display->display_options['fields']['cap_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['cap_url']['type'] = 'link_plain';
  /* Field: Field collection item: media (cap_media:delta) */
  $handler->display->display_options['fields']['delta_3']['id'] = 'delta_3';
  $handler->display->display_options['fields']['delta_3']['table'] = 'field_data_cap_media';
  $handler->display->display_options['fields']['delta_3']['field'] = 'delta';
  $handler->display->display_options['fields']['delta_3']['relationship'] = 'cap_researchprojects_value';
  $handler->display->display_options['fields']['delta_3']['label'] = 'Research project media delta';
  $handler->display->display_options['fields']['delta_3']['separator'] = '';
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
    'cap_faculty_profile' => 'cap_faculty_profile',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 1;
  $handler->display->display_options['style_options']['replace_newlines'] = 1;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'projects_export.csv';
  $export['stanford_cap_api_export_projects'] = $view;

  return $export;
}
