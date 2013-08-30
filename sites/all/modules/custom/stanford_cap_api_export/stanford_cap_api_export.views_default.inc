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
  $handler->display->display_options['fields']['cap_affiliations']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_affiliations']['settings'] = array(
    'view_mode' => 'full',
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
  $handler->display->display_options['fields']['cap_documents']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_documents']['settings'] = array(
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
  $handler->display->display_options['fields']['cap_workexperience']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['cap_workexperience']['settings'] = array(
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

  return $export;
}
