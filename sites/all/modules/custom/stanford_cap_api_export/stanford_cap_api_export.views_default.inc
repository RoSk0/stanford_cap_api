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
  $handler->display->display_options['fields']['cap_affiliations']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['cap_affiliations']['settings'] = array(
    'name' => 'stanford_cap_api_field_collection_view',
    'display_id' => 'default',
    'add' => 'Add',
  );
  $handler->display->display_options['fields']['cap_affiliations']['delta_offset'] = '0';
  /* Field: Content: alternateContact */
  $handler->display->display_options['fields']['cap_alternatecontact']['id'] = 'cap_alternatecontact';
  $handler->display->display_options['fields']['cap_alternatecontact']['table'] = 'field_data_cap_alternatecontact';
  $handler->display->display_options['fields']['cap_alternatecontact']['field'] = 'cap_alternatecontact';
  $handler->display->display_options['fields']['cap_alternatecontact']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_alternatecontact']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_alternatecontact']['delta_offset'] = '0';
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
  $handler->display->display_options['fields']['cap_clerkships']['delta_offset'] = '0';
  /* Field: Content: clinicalContacts */
  $handler->display->display_options['fields']['cap_clinicalcontacts']['id'] = 'cap_clinicalcontacts';
  $handler->display->display_options['fields']['cap_clinicalcontacts']['table'] = 'field_data_cap_clinicalcontacts';
  $handler->display->display_options['fields']['cap_clinicalcontacts']['field'] = 'cap_clinicalcontacts';
  $handler->display->display_options['fields']['cap_clinicalcontacts']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_clinicalcontacts']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_clinicalcontacts']['delta_offset'] = '0';
  /* Field: Content: clinicalFocus */
  $handler->display->display_options['fields']['cap_clinicalfocus']['id'] = 'cap_clinicalfocus';
  $handler->display->display_options['fields']['cap_clinicalfocus']['table'] = 'field_data_cap_clinicalfocus';
  $handler->display->display_options['fields']['cap_clinicalfocus']['field'] = 'cap_clinicalfocus';
  $handler->display->display_options['fields']['cap_clinicalfocus']['delta_offset'] = '0';
  /* Field: Content: clinicalInterests */
  $handler->display->display_options['fields']['cap_clinicalinterests']['id'] = 'cap_clinicalinterests';
  $handler->display->display_options['fields']['cap_clinicalinterests']['table'] = 'field_data_cap_clinicalinterests';
  $handler->display->display_options['fields']['cap_clinicalinterests']['field'] = 'cap_clinicalinterests';
  $handler->display->display_options['fields']['cap_clinicalinterests']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_clinicalinterests']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_clinicalinterests']['delta_offset'] = '0';
  /* Field: Content: coursesTaught */
  $handler->display->display_options['fields']['cap_coursestaught']['id'] = 'cap_coursestaught';
  $handler->display->display_options['fields']['cap_coursestaught']['table'] = 'field_data_cap_coursestaught';
  $handler->display->display_options['fields']['cap_coursestaught']['field'] = 'cap_coursestaught';
  $handler->display->display_options['fields']['cap_coursestaught']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_coursestaught']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_coursestaught']['delta_offset'] = '0';
  /* Field: Content: currentResearchInterests */
  $handler->display->display_options['fields']['cap_currentresearchinterests']['id'] = 'cap_currentresearchinterests';
  $handler->display->display_options['fields']['cap_currentresearchinterests']['table'] = 'field_data_cap_currentresearchinterests';
  $handler->display->display_options['fields']['cap_currentresearchinterests']['field'] = 'cap_currentresearchinterests';
  $handler->display->display_options['fields']['cap_currentresearchinterests']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_currentresearchinterests']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_currentresearchinterests']['delta_offset'] = '0';
  /* Field: Content: displayName */
  $handler->display->display_options['fields']['cap_displayname']['id'] = 'cap_displayname';
  $handler->display->display_options['fields']['cap_displayname']['table'] = 'field_data_cap_displayname';
  $handler->display->display_options['fields']['cap_displayname']['field'] = 'cap_displayname';
  /* Field: Content: documents */
  $handler->display->display_options['fields']['cap_documents']['id'] = 'cap_documents';
  $handler->display->display_options['fields']['cap_documents']['table'] = 'field_data_cap_documents';
  $handler->display->display_options['fields']['cap_documents']['field'] = 'cap_documents';
  $handler->display->display_options['fields']['cap_documents']['settings'] = array(
    'edit' => 'Edit',
    'delete' => 'Delete',
    'add' => 'Add',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_documents']['delta_offset'] = '0';
  /* Field: Content: education */
  $handler->display->display_options['fields']['cap_education']['id'] = 'cap_education';
  $handler->display->display_options['fields']['cap_education']['table'] = 'field_data_cap_education';
  $handler->display->display_options['fields']['cap_education']['field'] = 'cap_education';
  $handler->display->display_options['fields']['cap_education']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_education']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_education']['delta_offset'] = '0';
  /* Field: Content: graduateAndFellowshipPrograms */
  $handler->display->display_options['fields']['cap_graduateandfellowshipprogram']['id'] = 'cap_graduateandfellowshipprogram';
  $handler->display->display_options['fields']['cap_graduateandfellowshipprogram']['table'] = 'field_data_cap_graduateandfellowshipprogram';
  $handler->display->display_options['fields']['cap_graduateandfellowshipprogram']['field'] = 'cap_graduateandfellowshipprogram';
  $handler->display->display_options['fields']['cap_graduateandfellowshipprogram']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_graduateandfellowshipprogram']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_graduateandfellowshipprogram']['delta_offset'] = '0';
  /* Field: Content: honorsAndAwards */
  $handler->display->display_options['fields']['cap_honorsandawards']['id'] = 'cap_honorsandawards';
  $handler->display->display_options['fields']['cap_honorsandawards']['table'] = 'field_data_cap_honorsandawards';
  $handler->display->display_options['fields']['cap_honorsandawards']['field'] = 'cap_honorsandawards';
  $handler->display->display_options['fields']['cap_honorsandawards']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_honorsandawards']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_honorsandawards']['delta_offset'] = '0';
  /* Field: Content: internetLinks */
  $handler->display->display_options['fields']['cap_internetlinks']['id'] = 'cap_internetlinks';
  $handler->display->display_options['fields']['cap_internetlinks']['table'] = 'field_data_cap_internetlinks';
  $handler->display->display_options['fields']['cap_internetlinks']['field'] = 'cap_internetlinks';
  $handler->display->display_options['fields']['cap_internetlinks']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_internetlinks']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_internetlinks']['delta_offset'] = '0';
  /* Field: Content: keywords */
  $handler->display->display_options['fields']['cap_keywords']['id'] = 'cap_keywords';
  $handler->display->display_options['fields']['cap_keywords']['table'] = 'field_data_cap_keywords';
  $handler->display->display_options['fields']['cap_keywords']['field'] = 'cap_keywords';
  $handler->display->display_options['fields']['cap_keywords']['delta_offset'] = '0';
  /* Field: Content: labAffiliations */
  $handler->display->display_options['fields']['cap_labaffiliations']['id'] = 'cap_labaffiliations';
  $handler->display->display_options['fields']['cap_labaffiliations']['table'] = 'field_data_cap_labaffiliations';
  $handler->display->display_options['fields']['cap_labaffiliations']['field'] = 'cap_labaffiliations';
  $handler->display->display_options['fields']['cap_labaffiliations']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_labaffiliations']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_labaffiliations']['delta_offset'] = '0';
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
  $handler->display->display_options['fields']['cap_longtitle']['delta_offset'] = '0';
  /* Field: Content: membershipOrganizations */
  $handler->display->display_options['fields']['cap_membershiporganizations']['id'] = 'cap_membershiporganizations';
  $handler->display->display_options['fields']['cap_membershiporganizations']['table'] = 'field_data_cap_membershiporganizations';
  $handler->display->display_options['fields']['cap_membershiporganizations']['field'] = 'cap_membershiporganizations';
  $handler->display->display_options['fields']['cap_membershiporganizations']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_membershiporganizations']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_membershiporganizations']['delta_offset'] = '0';
  /* Field: Content: meta */
  $handler->display->display_options['fields']['cap_meta']['id'] = 'cap_meta';
  $handler->display->display_options['fields']['cap_meta']['table'] = 'field_data_cap_meta';
  $handler->display->display_options['fields']['cap_meta']['field'] = 'cap_meta';
  $handler->display->display_options['fields']['cap_meta']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_meta']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_meta']['delta_offset'] = '0';
  /* Field: Content: names */
  $handler->display->display_options['fields']['cap_names']['id'] = 'cap_names';
  $handler->display->display_options['fields']['cap_names']['table'] = 'field_data_cap_names';
  $handler->display->display_options['fields']['cap_names']['field'] = 'cap_names';
  $handler->display->display_options['fields']['cap_names']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_names']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_names']['delta_offset'] = '0';
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
  $handler->display->display_options['fields']['cap_presentations']['delta_offset'] = '0';
  /* Field: Content: primaryContact */
  $handler->display->display_options['fields']['cap_primarycontact']['id'] = 'cap_primarycontact';
  $handler->display->display_options['fields']['cap_primarycontact']['table'] = 'field_data_cap_primarycontact';
  $handler->display->display_options['fields']['cap_primarycontact']['field'] = 'cap_primarycontact';
  $handler->display->display_options['fields']['cap_primarycontact']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_primarycontact']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_primarycontact']['delta_offset'] = '0';
  /* Field: Content: profilePhotos */
  $handler->display->display_options['fields']['cap_profilephotos']['id'] = 'cap_profilephotos';
  $handler->display->display_options['fields']['cap_profilephotos']['table'] = 'field_data_cap_profilephotos';
  $handler->display->display_options['fields']['cap_profilephotos']['field'] = 'cap_profilephotos';
  $handler->display->display_options['fields']['cap_profilephotos']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_profilephotos']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_profilephotos']['delta_offset'] = '0';
  /* Field: Content: publications */
  $handler->display->display_options['fields']['cap_publications']['id'] = 'cap_publications';
  $handler->display->display_options['fields']['cap_publications']['table'] = 'field_data_cap_publications';
  $handler->display->display_options['fields']['cap_publications']['field'] = 'cap_publications';
  $handler->display->display_options['fields']['cap_publications']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_publications']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_publications']['delta_offset'] = '0';
  /* Field: Content: publicationTags */
  $handler->display->display_options['fields']['cap_publicationtags']['id'] = 'cap_publicationtags';
  $handler->display->display_options['fields']['cap_publicationtags']['table'] = 'field_data_cap_publicationtags';
  $handler->display->display_options['fields']['cap_publicationtags']['field'] = 'cap_publicationtags';
  $handler->display->display_options['fields']['cap_publicationtags']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_publicationtags']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_publicationtags']['delta_offset'] = '0';
  /* Field: Content: researchProjects */
  $handler->display->display_options['fields']['cap_researchprojects']['id'] = 'cap_researchprojects';
  $handler->display->display_options['fields']['cap_researchprojects']['table'] = 'field_data_cap_researchprojects';
  $handler->display->display_options['fields']['cap_researchprojects']['field'] = 'cap_researchprojects';
  $handler->display->display_options['fields']['cap_researchprojects']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_researchprojects']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_researchprojects']['delta_offset'] = '0';
  /* Field: Content: serviceWork */
  $handler->display->display_options['fields']['cap_servicework']['id'] = 'cap_servicework';
  $handler->display->display_options['fields']['cap_servicework']['table'] = 'field_data_cap_servicework';
  $handler->display->display_options['fields']['cap_servicework']['field'] = 'cap_servicework';
  $handler->display->display_options['fields']['cap_servicework']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_servicework']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_servicework']['delta_offset'] = '0';
  /* Field: Content: shortTitle */
  $handler->display->display_options['fields']['cap_shorttitle']['id'] = 'cap_shorttitle';
  $handler->display->display_options['fields']['cap_shorttitle']['table'] = 'field_data_cap_shorttitle';
  $handler->display->display_options['fields']['cap_shorttitle']['field'] = 'cap_shorttitle';
  $handler->display->display_options['fields']['cap_shorttitle']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_shorttitle']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_shorttitle']['delta_offset'] = '0';
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
  $handler->display->display_options['fields']['cap_similarprofiles']['delta_offset'] = '0';
  /* Field: Content: stanfordAdvisors */
  $handler->display->display_options['fields']['cap_stanfordadvisors']['id'] = 'cap_stanfordadvisors';
  $handler->display->display_options['fields']['cap_stanfordadvisors']['table'] = 'field_data_cap_stanfordadvisors';
  $handler->display->display_options['fields']['cap_stanfordadvisors']['field'] = 'cap_stanfordadvisors';
  $handler->display->display_options['fields']['cap_stanfordadvisors']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_stanfordadvisors']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_stanfordadvisors']['delta_offset'] = '0';
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
  $handler->display->display_options['fields']['cap_titles']['delta_offset'] = '0';
  /* Field: Content: workExperience */
  $handler->display->display_options['fields']['cap_workexperience']['id'] = 'cap_workexperience';
  $handler->display->display_options['fields']['cap_workexperience']['table'] = 'field_data_cap_workexperience';
  $handler->display->display_options['fields']['cap_workexperience']['field'] = 'cap_workexperience';
  $handler->display->display_options['fields']['cap_workexperience']['settings'] = array(
    'edit' => 'Edit',
    'delete' => 'Delete',
    'add' => 'Add',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['cap_workexperience']['delta_offset'] = '0';
  /* Field: Field: alias */
  $handler->display->display_options['fields']['cap_alias']['id'] = 'cap_alias';
  $handler->display->display_options['fields']['cap_alias']['table'] = 'field_data_cap_alias';
  $handler->display->display_options['fields']['cap_alias']['field'] = 'cap_alias';
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
  $view->name = 'stanford_cap_api_field_collection_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Stanford CAP API field collection view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'item_id' => 'item_id',
    'field_resume_job_title' => 'field_resume_job_title',
    'field_resume_time_period' => 'field_resume_time_period',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'item_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_resume_job_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_resume_time_period' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '[nothing_2]';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['footer']['area']['tokenize'] = TRUE;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  /* Field: Field collection item: Field path */
  $handler->display->display_options['fields']['field_path']['id'] = 'field_path';
  $handler->display->display_options['fields']['field_path']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['field_path']['field'] = 'field_path';
  $handler->display->display_options['fields']['field_path']['label'] = '';
  $handler->display->display_options['fields']['field_path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_path']['hide_alter_empty'] = FALSE;
  /* Field: Field collection item: Host Entity ID */
  $handler->display->display_options['fields']['host_entity_id']['id'] = 'host_entity_id';
  $handler->display->display_options['fields']['host_entity_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['host_entity_id']['field'] = 'host_entity_id';
  $handler->display->display_options['fields']['host_entity_id']['label'] = '';
  $handler->display->display_options['fields']['host_entity_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['host_entity_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['host_entity_id']['hide_alter_empty'] = FALSE;
  /* Field: Field collection item: Host Entity Path */
  $handler->display->display_options['fields']['host_entity_path']['id'] = 'host_entity_path';
  $handler->display->display_options['fields']['host_entity_path']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['host_entity_path']['field'] = 'host_entity_path';
  $handler->display->display_options['fields']['host_entity_path']['label'] = '';
  $handler->display->display_options['fields']['host_entity_path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['host_entity_path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['host_entity_path']['hide_alter_empty'] = FALSE;
  /* Field: Field collection item: Host Entity Type */
  $handler->display->display_options['fields']['host_entity_type']['id'] = 'host_entity_type';
  $handler->display->display_options['fields']['host_entity_type']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['host_entity_type']['field'] = 'host_entity_type';
  $handler->display->display_options['fields']['host_entity_type']['label'] = '';
  $handler->display->display_options['fields']['host_entity_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['host_entity_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['host_entity_type']['hide_alter_empty'] = FALSE;
  /* Field: Field: alias */
  $handler->display->display_options['fields']['cap_alias']['id'] = 'cap_alias';
  $handler->display->display_options['fields']['cap_alias']['table'] = 'field_data_cap_alias';
  $handler->display->display_options['fields']['cap_alias']['field'] = 'cap_alias';
  $handler->display->display_options['fields']['cap_alias']['type'] = 'text_plain';
  /* Field: Field: profileId */
  $handler->display->display_options['fields']['cap_profileid']['id'] = 'cap_profileid';
  $handler->display->display_options['fields']['cap_profileid']['table'] = 'field_data_cap_profileid';
  $handler->display->display_options['fields']['cap_profileid']['field'] = 'cap_profileid';
  $handler->display->display_options['fields']['cap_profileid']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['cap_profileid']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Field collection item: abstract */
  $handler->display->display_options['fields']['cap_abstract']['id'] = 'cap_abstract';
  $handler->display->display_options['fields']['cap_abstract']['table'] = 'field_data_cap_abstract';
  $handler->display->display_options['fields']['cap_abstract']['field'] = 'cap_abstract';
  $handler->display->display_options['fields']['cap_abstract']['type'] = 'text_plain';
  /* Field: Field collection item: academicInstituteDisplay */
  $handler->display->display_options['fields']['cap_academicinstitutedisplay']['id'] = 'cap_academicinstitutedisplay';
  $handler->display->display_options['fields']['cap_academicinstitutedisplay']['table'] = 'field_data_cap_academicinstitutedisplay';
  $handler->display->display_options['fields']['cap_academicinstitutedisplay']['field'] = 'cap_academicinstitutedisplay';
  /* Field: Field collection item: academicYear */
  $handler->display->display_options['fields']['cap_academicyear']['id'] = 'cap_academicyear';
  $handler->display->display_options['fields']['cap_academicyear']['table'] = 'field_data_cap_academicyear';
  $handler->display->display_options['fields']['cap_academicyear']['field'] = 'cap_academicyear';
  /* Field: Field collection item: address */
  $handler->display->display_options['fields']['cap_address']['id'] = 'cap_address';
  $handler->display->display_options['fields']['cap_address']['table'] = 'field_data_cap_address';
  $handler->display->display_options['fields']['cap_address']['field'] = 'cap_address';
  /* Field: Field collection item: address2 */
  $handler->display->display_options['fields']['cap_address2']['id'] = 'cap_address2';
  $handler->display->display_options['fields']['cap_address2']['table'] = 'field_data_cap_address2';
  $handler->display->display_options['fields']['cap_address2']['field'] = 'cap_address2';
  /* Field: Field collection item: advisor */
  $handler->display->display_options['fields']['cap_advisor']['id'] = 'cap_advisor';
  $handler->display->display_options['fields']['cap_advisor']['table'] = 'field_data_cap_advisor';
  $handler->display->display_options['fields']['cap_advisor']['field'] = 'cap_advisor';
  $handler->display->display_options['fields']['cap_advisor']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['cap_advisor']['settings'] = array(
    'name' => 'stanford_cap_api_field_collection_view',
    'display_id' => 'default',
    'add' => '',
  );
  $handler->display->display_options['fields']['cap_advisor']['delta_offset'] = '0';
  /* Field: Field collection item: apaCitation */
  $handler->display->display_options['fields']['cap_apacitation']['id'] = 'cap_apacitation';
  $handler->display->display_options['fields']['cap_apacitation']['table'] = 'field_data_cap_apacitation';
  $handler->display->display_options['fields']['cap_apacitation']['field'] = 'cap_apacitation';
  /* Field: Field collection item: apiLabel */
  $handler->display->display_options['fields']['cap_apilabel']['id'] = 'cap_apilabel';
  $handler->display->display_options['fields']['cap_apilabel']['table'] = 'field_data_cap_apilabel';
  $handler->display->display_options['fields']['cap_apilabel']['field'] = 'cap_apilabel';
  /* Field: Field collection item: Archived */
  $handler->display->display_options['fields']['archived']['id'] = 'archived';
  $handler->display->display_options['fields']['archived']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['archived']['field'] = 'archived';
  $handler->display->display_options['fields']['archived']['separator'] = '';
  /* Field: Field collection item: bannerDisplay */
  $handler->display->display_options['fields']['cap_bannerdisplay']['id'] = 'cap_bannerdisplay';
  $handler->display->display_options['fields']['cap_bannerdisplay']['table'] = 'field_data_cap_bannerdisplay';
  $handler->display->display_options['fields']['cap_bannerdisplay']['field'] = 'cap_bannerdisplay';
  /* Field: Field collection item: big */
  $handler->display->display_options['fields']['cap_big']['id'] = 'cap_big';
  $handler->display->display_options['fields']['cap_big']['table'] = 'field_data_cap_big';
  $handler->display->display_options['fields']['cap_big']['field'] = 'cap_big';
  $handler->display->display_options['fields']['cap_big']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['cap_big']['settings'] = array(
    'name' => 'stanford_cap_api_field_collection_view',
    'display_id' => 'default',
    'add' => '',
  );
  $handler->display->display_options['fields']['cap_big']['delta_offset'] = '0';
  /* Field: Field collection item: bigger */
  $handler->display->display_options['fields']['cap_bigger']['id'] = 'cap_bigger';
  $handler->display->display_options['fields']['cap_bigger']['table'] = 'field_data_cap_bigger';
  $handler->display->display_options['fields']['cap_bigger']['field'] = 'cap_bigger';
  $handler->display->display_options['fields']['cap_bigger']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['cap_bigger']['settings'] = array(
    'name' => 'stanford_cap_api_field_collection_view',
    'display_id' => 'default',
    'add' => '',
  );
  $handler->display->display_options['fields']['cap_bigger']['delta_offset'] = '0';
  /* Field: Field collection item: capFaculty */
  $handler->display->display_options['fields']['cap_capfaculty']['id'] = 'cap_capfaculty';
  $handler->display->display_options['fields']['cap_capfaculty']['table'] = 'field_data_cap_capfaculty';
  $handler->display->display_options['fields']['cap_capfaculty']['field'] = 'cap_capfaculty';
  /* Field: Field collection item: capMdStudent */
  $handler->display->display_options['fields']['cap_capmdstudent']['id'] = 'cap_capmdstudent';
  $handler->display->display_options['fields']['cap_capmdstudent']['table'] = 'field_data_cap_capmdstudent';
  $handler->display->display_options['fields']['cap_capmdstudent']['field'] = 'cap_capmdstudent';
  /* Field: Field collection item: capMsStudent */
  $handler->display->display_options['fields']['cap_capmsstudent']['id'] = 'cap_capmsstudent';
  $handler->display->display_options['fields']['cap_capmsstudent']['table'] = 'field_data_cap_capmsstudent';
  $handler->display->display_options['fields']['cap_capmsstudent']['field'] = 'cap_capmsstudent';
  /* Field: Field collection item: capPhdStudent */
  $handler->display->display_options['fields']['cap_capphdstudent']['id'] = 'cap_capphdstudent';
  $handler->display->display_options['fields']['cap_capphdstudent']['table'] = 'field_data_cap_capphdstudent';
  $handler->display->display_options['fields']['cap_capphdstudent']['field'] = 'cap_capphdstudent';
  /* Field: Field collection item: capPostdoc */
  $handler->display->display_options['fields']['cap_cappostdoc']['id'] = 'cap_cappostdoc';
  $handler->display->display_options['fields']['cap_cappostdoc']['table'] = 'field_data_cap_cappostdoc';
  $handler->display->display_options['fields']['cap_cappostdoc']['field'] = 'cap_cappostdoc';
  /* Field: Field collection item: capStaff */
  $handler->display->display_options['fields']['cap_capstaff']['id'] = 'cap_capstaff';
  $handler->display->display_options['fields']['cap_capstaff']['table'] = 'field_data_cap_capstaff';
  $handler->display->display_options['fields']['cap_capstaff']['field'] = 'cap_capstaff';
  /* Field: Field collection item: catalogNumber */
  $handler->display->display_options['fields']['cap_catalognumber']['id'] = 'cap_catalognumber';
  $handler->display->display_options['fields']['cap_catalognumber']['table'] = 'field_data_cap_catalognumber';
  $handler->display->display_options['fields']['cap_catalognumber']['field'] = 'cap_catalognumber';
  /* Field: Field collection item: chicagoCitation */
  $handler->display->display_options['fields']['cap_chicagocitation']['id'] = 'cap_chicagocitation';
  $handler->display->display_options['fields']['cap_chicagocitation']['table'] = 'field_data_cap_chicagocitation';
  $handler->display->display_options['fields']['cap_chicagocitation']['field'] = 'cap_chicagocitation';
  /* Field: Field collection item: city */
  $handler->display->display_options['fields']['cap_city']['id'] = 'cap_city';
  $handler->display->display_options['fields']['cap_city']['table'] = 'field_data_cap_city';
  $handler->display->display_options['fields']['cap_city']['field'] = 'cap_city';
  /* Field: Field collection item: collaborators */
  $handler->display->display_options['fields']['cap_collaborators']['id'] = 'cap_collaborators';
  $handler->display->display_options['fields']['cap_collaborators']['table'] = 'field_data_cap_collaborators';
  $handler->display->display_options['fields']['cap_collaborators']['field'] = 'cap_collaborators';
  $handler->display->display_options['fields']['cap_collaborators']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['cap_collaborators']['settings'] = array(
    'name' => 'stanford_cap_api_field_collection_view',
    'display_id' => 'default',
    'add' => '',
  );
  $handler->display->display_options['fields']['cap_collaborators']['delta_offset'] = '0';
  /* Field: Field collection item: contentType */
  $handler->display->display_options['fields']['cap_contenttype']['id'] = 'cap_contenttype';
  $handler->display->display_options['fields']['cap_contenttype']['table'] = 'field_data_cap_contenttype';
  $handler->display->display_options['fields']['cap_contenttype']['field'] = 'cap_contenttype';
  /* Field: Field collection item: courses */
  $handler->display->display_options['fields']['cap_courses']['id'] = 'cap_courses';
  $handler->display->display_options['fields']['cap_courses']['table'] = 'field_data_cap_courses';
  $handler->display->display_options['fields']['cap_courses']['field'] = 'cap_courses';
  $handler->display->display_options['fields']['cap_courses']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['cap_courses']['settings'] = array(
    'name' => 'stanford_cap_api_field_collection_view',
    'display_id' => 'default',
    'add' => '',
  );
  $handler->display->display_options['fields']['cap_courses']['delta_offset'] = '0';
  /* Field: Field collection item: cv */
  $handler->display->display_options['fields']['cap_cv']['id'] = 'cap_cv';
  $handler->display->display_options['fields']['cap_cv']['table'] = 'field_data_cap_cv';
  $handler->display->display_options['fields']['cap_cv']['field'] = 'cap_cv';
  $handler->display->display_options['fields']['cap_cv']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['cap_cv']['settings'] = array(
    'name' => 'field_collection_view',
    'display_id' => 'default',
    'add' => '',
  );
  $handler->display->display_options['fields']['cap_cv']['delta_offset'] = '0';
  /* Field: Field collection item: dates */
  $handler->display->display_options['fields']['cap_dates']['id'] = 'cap_dates';
  $handler->display->display_options['fields']['cap_dates']['table'] = 'field_data_cap_dates';
  $handler->display->display_options['fields']['cap_dates']['field'] = 'cap_dates';
  /* Field: Field collection item: degree */
  $handler->display->display_options['fields']['cap_degree']['id'] = 'cap_degree';
  $handler->display->display_options['fields']['cap_degree']['table'] = 'field_data_cap_degree';
  $handler->display->display_options['fields']['cap_degree']['field'] = 'cap_degree';
  /* Field: Field collection item: department */
  $handler->display->display_options['fields']['cap_department']['id'] = 'cap_department';
  $handler->display->display_options['fields']['cap_department']['table'] = 'field_data_cap_department';
  $handler->display->display_options['fields']['cap_department']['field'] = 'cap_department';
  /* Field: Field collection item: description */
  $handler->display->display_options['fields']['cap_description']['id'] = 'cap_description';
  $handler->display->display_options['fields']['cap_description']['table'] = 'field_data_cap_description';
  $handler->display->display_options['fields']['cap_description']['field'] = 'cap_description';
  /* Field: Field collection item: details */
  $handler->display->display_options['fields']['cap_details']['id'] = 'cap_details';
  $handler->display->display_options['fields']['cap_details']['table'] = 'field_data_cap_details';
  $handler->display->display_options['fields']['cap_details']['field'] = 'cap_details';
  /* Field: Field collection item: doiUrl */
  $handler->display->display_options['fields']['cap_doiurl']['id'] = 'cap_doiurl';
  $handler->display->display_options['fields']['cap_doiurl']['table'] = 'field_data_cap_doiurl';
  $handler->display->display_options['fields']['cap_doiurl']['field'] = 'cap_doiurl';
  $handler->display->display_options['fields']['cap_doiurl']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['cap_doiurl']['type'] = 'link_plain';
  /* Field: Field collection item: email */
  $handler->display->display_options['fields']['cap_email']['id'] = 'cap_email';
  $handler->display->display_options['fields']['cap_email']['table'] = 'field_data_cap_email';
  $handler->display->display_options['fields']['cap_email']['field'] = 'cap_email';
  /* Field: Field collection item: endDate */
  $handler->display->display_options['fields']['cap_enddate']['id'] = 'cap_enddate';
  $handler->display->display_options['fields']['cap_enddate']['table'] = 'field_data_cap_enddate';
  $handler->display->display_options['fields']['cap_enddate']['field'] = 'cap_enddate';
  $handler->display->display_options['fields']['cap_enddate']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field collection item: etag */
  $handler->display->display_options['fields']['cap_etag']['id'] = 'cap_etag';
  $handler->display->display_options['fields']['cap_etag']['table'] = 'field_data_cap_etag';
  $handler->display->display_options['fields']['cap_etag']['field'] = 'cap_etag';
  /* Field: Field collection item: featured */
  $handler->display->display_options['fields']['cap_featured']['id'] = 'cap_featured';
  $handler->display->display_options['fields']['cap_featured']['table'] = 'field_data_cap_featured';
  $handler->display->display_options['fields']['cap_featured']['field'] = 'cap_featured';
  /* Field: Field collection item: Field name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  /* Field: Field collection item: fieldOfStudy */
  $handler->display->display_options['fields']['cap_fieldofstudy']['id'] = 'cap_fieldofstudy';
  $handler->display->display_options['fields']['cap_fieldofstudy']['table'] = 'field_data_cap_fieldofstudy';
  $handler->display->display_options['fields']['cap_fieldofstudy']['field'] = 'cap_fieldofstudy';
  /* Field: Field collection item: firstName */
  $handler->display->display_options['fields']['cap_firstname']['id'] = 'cap_firstname';
  $handler->display->display_options['fields']['cap_firstname']['table'] = 'field_data_cap_firstname';
  $handler->display->display_options['fields']['cap_firstname']['field'] = 'cap_firstname';
  /* Field: Field collection item: firstPublished */
  $handler->display->display_options['fields']['cap_firstpublished']['id'] = 'cap_firstpublished';
  $handler->display->display_options['fields']['cap_firstpublished']['table'] = 'field_data_cap_firstpublished';
  $handler->display->display_options['fields']['cap_firstpublished']['field'] = 'cap_firstpublished';
  $handler->display->display_options['fields']['cap_firstpublished']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field collection item: fullName */
  $handler->display->display_options['fields']['cap_fullname']['id'] = 'cap_fullname';
  $handler->display->display_options['fields']['cap_fullname']['table'] = 'field_data_cap_fullname';
  $handler->display->display_options['fields']['cap_fullname']['field'] = 'cap_fullname';
  /* Field: Field collection item: fullText */
  $handler->display->display_options['fields']['cap_fulltext']['id'] = 'cap_fulltext';
  $handler->display->display_options['fields']['cap_fulltext']['table'] = 'field_data_cap_fulltext';
  $handler->display->display_options['fields']['cap_fulltext']['field'] = 'cap_fulltext';
  /* Field: Field collection item: independentStudyCourses */
  $handler->display->display_options['fields']['cap_independentstudycourses']['id'] = 'cap_independentstudycourses';
  $handler->display->display_options['fields']['cap_independentstudycourses']['table'] = 'field_data_cap_independentstudycourses';
  $handler->display->display_options['fields']['cap_independentstudycourses']['field'] = 'cap_independentstudycourses';
  $handler->display->display_options['fields']['cap_independentstudycourses']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['cap_independentstudycourses']['settings'] = array(
    'name' => 'stanford_cap_api_field_collection_view',
    'display_id' => 'default',
    'add' => '',
  );
  $handler->display->display_options['fields']['cap_independentstudycourses']['delta_offset'] = '0';
  /* Field: Field collection item: independentStudyInd */
  $handler->display->display_options['fields']['cap_independentstudyind']['id'] = 'cap_independentstudyind';
  $handler->display->display_options['fields']['cap_independentstudyind']['table'] = 'field_data_cap_independentstudyind';
  $handler->display->display_options['fields']['cap_independentstudyind']['field'] = 'cap_independentstudyind';
  /* Field: Field collection item: institution */
  $handler->display->display_options['fields']['cap_institution']['id'] = 'cap_institution';
  $handler->display->display_options['fields']['cap_institution']['table'] = 'field_data_cap_institution';
  $handler->display->display_options['fields']['cap_institution']['field'] = 'cap_institution';
  /* Field: Field collection item: key */
  $handler->display->display_options['fields']['cap_key']['id'] = 'cap_key';
  $handler->display->display_options['fields']['cap_key']['table'] = 'field_data_cap_key';
  $handler->display->display_options['fields']['cap_key']['field'] = 'cap_key';
  /* Field: Field collection item: lab */
  $handler->display->display_options['fields']['cap_lab']['id'] = 'cap_lab';
  $handler->display->display_options['fields']['cap_lab']['table'] = 'field_data_cap_lab';
  $handler->display->display_options['fields']['cap_lab']['field'] = 'cap_lab';
  /* Field: Field collection item: label */
  $handler->display->display_options['fields']['cap_label']['id'] = 'cap_label';
  $handler->display->display_options['fields']['cap_label']['table'] = 'field_data_cap_label';
  $handler->display->display_options['fields']['cap_label']['field'] = 'cap_label';
  /* Field: Field collection item: lastName */
  $handler->display->display_options['fields']['cap_lastname']['id'] = 'cap_lastname';
  $handler->display->display_options['fields']['cap_lastname']['table'] = 'field_data_cap_lastname';
  $handler->display->display_options['fields']['cap_lastname']['field'] = 'cap_lastname';
  /* Field: Field collection item: legal */
  $handler->display->display_options['fields']['cap_legal']['id'] = 'cap_legal';
  $handler->display->display_options['fields']['cap_legal']['table'] = 'field_data_cap_legal';
  $handler->display->display_options['fields']['cap_legal']['field'] = 'cap_legal';
  $handler->display->display_options['fields']['cap_legal']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['cap_legal']['settings'] = array(
    'name' => 'stanford_cap_api_field_collection_view',
    'display_id' => 'default',
    'add' => '',
  );
  $handler->display->display_options['fields']['cap_legal']['delta_offset'] = '0';
  /* Field: Field collection item: links */
  $handler->display->display_options['fields']['cap_links']['id'] = 'cap_links';
  $handler->display->display_options['fields']['cap_links']['table'] = 'field_data_cap_links';
  $handler->display->display_options['fields']['cap_links']['field'] = 'cap_links';
  $handler->display->display_options['fields']['cap_links']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['cap_links']['settings'] = array(
    'name' => 'stanford_cap_api_field_collection_view',
    'display_id' => 'default',
    'add' => '',
  );
  $handler->display->display_options['fields']['cap_links']['delta_offset'] = '0';
  /* Field: Field collection item: location */
  $handler->display->display_options['fields']['cap_location']['id'] = 'cap_location';
  $handler->display->display_options['fields']['cap_location']['table'] = 'field_data_cap_location';
  $handler->display->display_options['fields']['cap_location']['field'] = 'cap_location';
  /* Field: Field collection item: media */
  $handler->display->display_options['fields']['cap_media']['id'] = 'cap_media';
  $handler->display->display_options['fields']['cap_media']['table'] = 'field_data_cap_media';
  $handler->display->display_options['fields']['cap_media']['field'] = 'cap_media';
  $handler->display->display_options['fields']['cap_media']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['cap_media']['settings'] = array(
    'name' => 'stanford_cap_api_field_collection_view',
    'display_id' => 'default',
    'add' => '',
  );
  $handler->display->display_options['fields']['cap_media']['delta_offset'] = '0';
  /* Field: Field collection item: middleName */
  $handler->display->display_options['fields']['cap_middlename']['id'] = 'cap_middlename';
  $handler->display->display_options['fields']['cap_middlename']['table'] = 'field_data_cap_middlename';
  $handler->display->display_options['fields']['cap_middlename']['field'] = 'cap_middlename';
  /* Field: Field collection item: mlaCitation */
  $handler->display->display_options['fields']['cap_mlacitation']['id'] = 'cap_mlacitation';
  $handler->display->display_options['fields']['cap_mlacitation']['table'] = 'field_data_cap_mlacitation';
  $handler->display->display_options['fields']['cap_mlacitation']['field'] = 'cap_mlacitation';
  /* Field: Field collection item: name */
  $handler->display->display_options['fields']['cap_name']['id'] = 'cap_name';
  $handler->display->display_options['fields']['cap_name']['table'] = 'field_data_cap_name';
  $handler->display->display_options['fields']['cap_name']['field'] = 'cap_name';
  /* Field: Field collection item: nihBiosketch */
  $handler->display->display_options['fields']['cap_nihbiosketch']['id'] = 'cap_nihbiosketch';
  $handler->display->display_options['fields']['cap_nihbiosketch']['table'] = 'field_data_cap_nihbiosketch';
  $handler->display->display_options['fields']['cap_nihbiosketch']['field'] = 'cap_nihbiosketch';
  $handler->display->display_options['fields']['cap_nihbiosketch']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['cap_nihbiosketch']['settings'] = array(
    'name' => 'stanford_cap_api_field_collection_view',
    'display_id' => 'default',
    'add' => '',
  );
  $handler->display->display_options['fields']['cap_nihbiosketch']['delta_offset'] = '0';
  /* Field: Field collection item: officeName */
  $handler->display->display_options['fields']['cap_officename']['id'] = 'cap_officename';
  $handler->display->display_options['fields']['cap_officename']['table'] = 'field_data_cap_officename';
  $handler->display->display_options['fields']['cap_officename']['field'] = 'cap_officename';
  /* Field: Field collection item: origCourses */
  $handler->display->display_options['fields']['cap_origcourses']['id'] = 'cap_origcourses';
  $handler->display->display_options['fields']['cap_origcourses']['table'] = 'field_data_cap_origcourses';
  $handler->display->display_options['fields']['cap_origcourses']['field'] = 'cap_origcourses';
  $handler->display->display_options['fields']['cap_origcourses']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['cap_origcourses']['settings'] = array(
    'name' => 'stanford_cap_api_field_collection_view',
    'display_id' => 'default',
    'add' => '',
  );
  $handler->display->display_options['fields']['cap_origcourses']['delta_offset'] = '0';
  /* Field: Field collection item: phoneNumbers */
  $handler->display->display_options['fields']['cap_phonenumbers']['id'] = 'cap_phonenumbers';
  $handler->display->display_options['fields']['cap_phonenumbers']['table'] = 'field_data_cap_phonenumbers';
  $handler->display->display_options['fields']['cap_phonenumbers']['field'] = 'cap_phonenumbers';
  $handler->display->display_options['fields']['cap_phonenumbers']['delta_offset'] = '0';
  /* Field: Field collection item: physician */
  $handler->display->display_options['fields']['cap_physician']['id'] = 'cap_physician';
  $handler->display->display_options['fields']['cap_physician']['table'] = 'field_data_cap_physician';
  $handler->display->display_options['fields']['cap_physician']['field'] = 'cap_physician';
  /* Field: Field collection item: placeholder */
  $handler->display->display_options['fields']['cap_placeholder']['id'] = 'cap_placeholder';
  $handler->display->display_options['fields']['cap_placeholder']['table'] = 'field_data_cap_placeholder';
  $handler->display->display_options['fields']['cap_placeholder']['field'] = 'cap_placeholder';
  /* Field: Field collection item: position */
  $handler->display->display_options['fields']['cap_position']['id'] = 'cap_position';
  $handler->display->display_options['fields']['cap_position']['table'] = 'field_data_cap_position';
  $handler->display->display_options['fields']['cap_position']['field'] = 'cap_position';
  /* Field: Field collection item: preferred */
  $handler->display->display_options['fields']['cap_preferred']['id'] = 'cap_preferred';
  $handler->display->display_options['fields']['cap_preferred']['table'] = 'field_data_cap_preferred';
  $handler->display->display_options['fields']['cap_preferred']['field'] = 'cap_preferred';
  $handler->display->display_options['fields']['cap_preferred']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['cap_preferred']['settings'] = array(
    'name' => 'stanford_cap_api_field_collection_view',
    'display_id' => 'default',
    'add' => '',
  );
  $handler->display->display_options['fields']['cap_preferred']['delta_offset'] = '0';
  /* Field: Field collection item: presentedTo */
  $handler->display->display_options['fields']['cap_presentedto']['id'] = 'cap_presentedto';
  $handler->display->display_options['fields']['cap_presentedto']['table'] = 'field_data_cap_presentedto';
  $handler->display->display_options['fields']['cap_presentedto']['field'] = 'cap_presentedto';
  /* Field: Field collection item: principalInvestigator */
  $handler->display->display_options['fields']['cap_principalinvestigator']['id'] = 'cap_principalinvestigator';
  $handler->display->display_options['fields']['cap_principalinvestigator']['table'] = 'field_data_cap_principalinvestigator';
  $handler->display->display_options['fields']['cap_principalinvestigator']['field'] = 'cap_principalinvestigator';
  /* Field: Field collection item: profileUrl */
  $handler->display->display_options['fields']['cap_profileurl']['id'] = 'cap_profileurl';
  $handler->display->display_options['fields']['cap_profileurl']['table'] = 'field_data_cap_profileurl';
  $handler->display->display_options['fields']['cap_profileurl']['field'] = 'cap_profileurl';
  $handler->display->display_options['fields']['cap_profileurl']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['cap_profileurl']['type'] = 'link_plain';
  /* Field: Field collection item: projectType */
  $handler->display->display_options['fields']['cap_projecttype']['id'] = 'cap_projecttype';
  $handler->display->display_options['fields']['cap_projecttype']['table'] = 'field_data_cap_projecttype';
  $handler->display->display_options['fields']['cap_projecttype']['field'] = 'cap_projecttype';
  $handler->display->display_options['fields']['cap_projecttype']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['cap_projecttype']['settings'] = array(
    'name' => 'stanford_cap_api_field_collection_view',
    'display_id' => 'default',
    'add' => '',
  );
  $handler->display->display_options['fields']['cap_projecttype']['delta_offset'] = '0';
  /* Field: Field collection item: publicationId */
  $handler->display->display_options['fields']['cap_publicationid']['id'] = 'cap_publicationid';
  $handler->display->display_options['fields']['cap_publicationid']['table'] = 'field_data_cap_publicationid';
  $handler->display->display_options['fields']['cap_publicationid']['field'] = 'cap_publicationid';
  $handler->display->display_options['fields']['cap_publicationid']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['cap_publicationid']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: quarter */
  $handler->display->display_options['fields']['cap_quarter']['id'] = 'cap_quarter';
  $handler->display->display_options['fields']['cap_quarter']['table'] = 'field_data_cap_quarter';
  $handler->display->display_options['fields']['cap_quarter']['field'] = 'cap_quarter';
  /* Field: Field collection item: rel */
  $handler->display->display_options['fields']['cap_rel']['id'] = 'cap_rel';
  $handler->display->display_options['fields']['cap_rel']['table'] = 'field_data_cap_rel';
  $handler->display->display_options['fields']['cap_rel']['field'] = 'cap_rel';
  /* Field: Field collection item: resume */
  $handler->display->display_options['fields']['cap_resume']['id'] = 'cap_resume';
  $handler->display->display_options['fields']['cap_resume']['table'] = 'field_data_cap_resume';
  $handler->display->display_options['fields']['cap_resume']['field'] = 'cap_resume';
  $handler->display->display_options['fields']['cap_resume']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['cap_resume']['settings'] = array(
    'name' => 'stanford_cap_api_field_collection_view',
    'display_id' => 'default',
    'add' => '',
  );
  $handler->display->display_options['fields']['cap_resume']['delta_offset'] = '0';
  /* Field: Field collection item: role */
  $handler->display->display_options['fields']['cap_role']['id'] = 'cap_role';
  $handler->display->display_options['fields']['cap_role']['table'] = 'field_data_cap_role';
  $handler->display->display_options['fields']['cap_role']['field'] = 'cap_role';
  /* Field: Field collection item: shortText */
  $handler->display->display_options['fields']['cap_shorttext']['id'] = 'cap_shorttext';
  $handler->display->display_options['fields']['cap_shorttext']['table'] = 'field_data_cap_shorttext';
  $handler->display->display_options['fields']['cap_shorttext']['field'] = 'cap_shorttext';
  /* Field: Field collection item: small */
  $handler->display->display_options['fields']['cap_small']['id'] = 'cap_small';
  $handler->display->display_options['fields']['cap_small']['table'] = 'field_data_cap_small';
  $handler->display->display_options['fields']['cap_small']['field'] = 'cap_small';
  $handler->display->display_options['fields']['cap_small']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['cap_small']['settings'] = array(
    'name' => 'stanford_cap_api_field_collection_view',
    'display_id' => 'default',
    'add' => '',
  );
  $handler->display->display_options['fields']['cap_small']['delta_offset'] = '0';
  /* Field: Field collection item: square */
  $handler->display->display_options['fields']['cap_square']['id'] = 'cap_square';
  $handler->display->display_options['fields']['cap_square']['table'] = 'field_data_cap_square';
  $handler->display->display_options['fields']['cap_square']['field'] = 'cap_square';
  $handler->display->display_options['fields']['cap_square']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['cap_square']['settings'] = array(
    'name' => 'stanford_cap_api_field_collection_view',
    'display_id' => 'default',
    'add' => '',
  );
  $handler->display->display_options['fields']['cap_square']['delta_offset'] = '0';
  /* Field: Field collection item: startDate */
  $handler->display->display_options['fields']['cap_startdate']['id'] = 'cap_startdate';
  $handler->display->display_options['fields']['cap_startdate']['table'] = 'field_data_cap_startdate';
  $handler->display->display_options['fields']['cap_startdate']['field'] = 'cap_startdate';
  $handler->display->display_options['fields']['cap_startdate']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field collection item: state */
  $handler->display->display_options['fields']['cap_state']['id'] = 'cap_state';
  $handler->display->display_options['fields']['cap_state']['table'] = 'field_data_cap_state';
  $handler->display->display_options['fields']['cap_state']['field'] = 'cap_state';
  /* Field: Field collection item: subject */
  $handler->display->display_options['fields']['cap_subject']['id'] = 'cap_subject';
  $handler->display->display_options['fields']['cap_subject']['table'] = 'field_data_cap_subject';
  $handler->display->display_options['fields']['cap_subject']['field'] = 'cap_subject';
  /* Field: Field collection item: subjectCode */
  $handler->display->display_options['fields']['cap_subjectcode']['id'] = 'cap_subjectcode';
  $handler->display->display_options['fields']['cap_subjectcode']['table'] = 'field_data_cap_subjectcode';
  $handler->display->display_options['fields']['cap_subjectcode']['field'] = 'cap_subjectcode';
  /* Field: Field collection item: terms */
  $handler->display->display_options['fields']['cap_terms']['id'] = 'cap_terms';
  $handler->display->display_options['fields']['cap_terms']['table'] = 'field_data_cap_terms';
  $handler->display->display_options['fields']['cap_terms']['field'] = 'cap_terms';
  $handler->display->display_options['fields']['cap_terms']['delta_offset'] = '0';
  /* Field: Field collection item: terseText */
  $handler->display->display_options['fields']['cap_tersetext']['id'] = 'cap_tersetext';
  $handler->display->display_options['fields']['cap_tersetext']['table'] = 'field_data_cap_tersetext';
  $handler->display->display_options['fields']['cap_tersetext']['field'] = 'cap_tersetext';
  /* Field: Field collection item: title */
  $handler->display->display_options['fields']['cap_title']['id'] = 'cap_title';
  $handler->display->display_options['fields']['cap_title']['table'] = 'field_data_cap_title';
  $handler->display->display_options['fields']['cap_title']['field'] = 'cap_title';
  /* Field: Field collection item: type */
  $handler->display->display_options['fields']['cap_type']['id'] = 'cap_type';
  $handler->display->display_options['fields']['cap_type']['table'] = 'field_data_cap_type';
  $handler->display->display_options['fields']['cap_type']['field'] = 'cap_type';
  /* Field: Field collection item: url */
  $handler->display->display_options['fields']['cap_url']['id'] = 'cap_url';
  $handler->display->display_options['fields']['cap_url']['table'] = 'field_data_cap_url';
  $handler->display->display_options['fields']['cap_url']['field'] = 'cap_url';
  $handler->display->display_options['fields']['cap_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['cap_url']['type'] = 'link_plain';
  /* Field: Field collection item: value */
  $handler->display->display_options['fields']['cap_value']['id'] = 'cap_value';
  $handler->display->display_options['fields']['cap_value']['table'] = 'field_data_cap_value';
  $handler->display->display_options['fields']['cap_value']['field'] = 'cap_value';
  /* Field: Field collection item: weight */
  $handler->display->display_options['fields']['cap_weight']['id'] = 'cap_weight';
  $handler->display->display_options['fields']['cap_weight']['table'] = 'field_data_cap_weight';
  $handler->display->display_options['fields']['cap_weight']['field'] = 'cap_weight';
  $handler->display->display_options['fields']['cap_weight']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['cap_weight']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: year */
  $handler->display->display_options['fields']['cap_year']['id'] = 'cap_year';
  $handler->display->display_options['fields']['cap_year']['table'] = 'field_data_cap_year';
  $handler->display->display_options['fields']['cap_year']['field'] = 'cap_year';
  $handler->display->display_options['fields']['cap_year']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field collection item: yearIssued */
  $handler->display->display_options['fields']['cap_yearissued']['id'] = 'cap_yearissued';
  $handler->display->display_options['fields']['cap_yearissued']['table'] = 'field_data_cap_yearissued';
  $handler->display->display_options['fields']['cap_yearissued']['field'] = 'cap_yearissued';
  /* Field: Field collection item: zip */
  $handler->display->display_options['fields']['cap_zip']['id'] = 'cap_zip';
  $handler->display->display_options['fields']['cap_zip']['table'] = 'field_data_cap_zip';
  $handler->display->display_options['fields']['cap_zip']['field'] = 'cap_zip';
  /* Sort criterion: Field collection item: Field collection item ID */
  $handler->display->display_options['sorts']['item_id']['id'] = 'item_id';
  $handler->display->display_options['sorts']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['sorts']['item_id']['field'] = 'item_id';
  /* Contextual filter: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['item_id']['break_phrase'] = TRUE;
  $export['stanford_cap_api_field_collection_view'] = $view;

  return $export;
}
