<?php
/**
 * @file
 * stanford_cap_profile_displays.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_cap_profile_displays_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cap_academic_contact_info|node|cap_stanford_profile|profile_page';
  $field_group->group_name = 'group_cap_academic_contact_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cap_stanford_profile';
  $field_group->mode = 'profile_page';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Academic and Contact Information',
    'weight' => '5',
    'children' => array(
      0 => 'cap_alternatecontact',
      1 => 'cap_clinicalcontacts',
      2 => 'cap_clinicalpractices',
      3 => 'cap_supervisors',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Academic and Contact Information',
      'instance_settings' => array(
        'classes' => 'group-cap-academic-contact-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_cap_academic_contact_info|node|cap_stanford_profile|profile_page'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cap_academic_contact_info|node|cap_stanford_profile|profile_page_tabbed';
  $field_group->group_name = 'group_cap_academic_contact_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cap_stanford_profile';
  $field_group->mode = 'profile_page_tabbed';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Academic and Contact Information',
    'weight' => '5',
    'children' => array(
      0 => 'cap_alternatecontact',
      1 => 'cap_clinicalcontacts',
      2 => 'cap_clinicalpractices',
      3 => 'cap_supervisors',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Academic and Contact Information',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-cap-academic-contact-info field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_cap_academic_contact_info|node|cap_stanford_profile|profile_page_tabbed'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cap_bio|node|cap_stanford_profile|profile_page';
  $field_group->group_name = 'group_cap_bio';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cap_stanford_profile';
  $field_group->mode = 'profile_page';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bio',
    'weight' => '4',
    'children' => array(
      0 => 'cap_administrativeappointment',
      1 => 'cap_bio',
      2 => 'cap_clerkships',
      3 => 'cap_clinicalcare',
      4 => 'cap_clinicalfocus',
      5 => 'cap_communityandinternational',
      6 => 'cap_currentroleatstanford',
      7 => 'cap_education',
      8 => 'cap_honorsandawards',
      9 => 'cap_internetlinks',
      10 => 'cap_membershiporganizations',
      11 => 'cap_patents',
      12 => 'cap_personalinterests',
      13 => 'cap_professionalorganizations',
      14 => 'cap_servicework',
      15 => 'cap_stanfordadvisors',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Bio',
      'instance_settings' => array(
        'classes' => 'group-cap-bio field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_cap_bio|node|cap_stanford_profile|profile_page'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cap_bio|node|cap_stanford_profile|profile_page_tabbed';
  $field_group->group_name = 'group_cap_bio';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cap_stanford_profile';
  $field_group->mode = 'profile_page_tabbed';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Bio',
    'weight' => '4',
    'children' => array(
      0 => 'cap_administrativeappointment',
      1 => 'cap_bio',
      2 => 'cap_clerkships',
      3 => 'cap_clinicalcare',
      4 => 'cap_clinicalfocus',
      5 => 'cap_communityandinternational',
      6 => 'cap_currentroleatstanford',
      7 => 'cap_education',
      8 => 'cap_honorsandawards',
      9 => 'cap_internetlinks',
      10 => 'cap_membershiporganizations',
      11 => 'cap_patents',
      12 => 'cap_personalinterests',
      13 => 'cap_professionalorganizations',
      14 => 'cap_servicework',
      15 => 'cap_stanfordadvisors',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Bio',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-cap-bio field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_cap_bio|node|cap_stanford_profile|profile_page_tabbed'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cap_professional|node|cap_stanford_profile|profile_page';
  $field_group->group_name = 'group_cap_professional';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cap_stanford_profile';
  $field_group->mode = 'profile_page';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Professional',
    'weight' => '8',
    'children' => array(
      0 => 'cap_professionalinterests',
      1 => 'cap_workexperience',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Professional',
      'instance_settings' => array(
        'classes' => 'group-cap-professional field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_cap_professional|node|cap_stanford_profile|profile_page'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cap_professional|node|cap_stanford_profile|profile_page_tabbed';
  $field_group->group_name = 'group_cap_professional';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cap_stanford_profile';
  $field_group->mode = 'profile_page_tabbed';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Professional',
    'weight' => '8',
    'children' => array(
      0 => 'cap_professionalinterests',
      1 => 'cap_workexperience',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Professional',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-cap-professional field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_cap_professional|node|cap_stanford_profile|profile_page_tabbed'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cap_publications|node|cap_stanford_profile|profile_page';
  $field_group->group_name = 'group_cap_publications';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cap_stanford_profile';
  $field_group->mode = 'profile_page';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Publications',
    'weight' => '9',
    'children' => array(
      0 => 'cap_presentations',
      1 => 'cap_publications',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cap-publications field-group-fieldset',
      ),
    ),
  );
  $export['group_cap_publications|node|cap_stanford_profile|profile_page'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cap_publications|node|cap_stanford_profile|profile_page_tabbed';
  $field_group->group_name = 'group_cap_publications';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cap_stanford_profile';
  $field_group->mode = 'profile_page_tabbed';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Publications',
    'weight' => '9',
    'children' => array(
      0 => 'cap_presentations',
      1 => 'cap_publications',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'id' => '',
        'description' => '',
        'classes' => 'group-cap-publications field-group-htab',
      ),
    ),
  );
  $export['group_cap_publications|node|cap_stanford_profile|profile_page_tabbed'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cap_teaching|node|cap_stanford_profile|profile_page';
  $field_group->group_name = 'group_cap_teaching';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cap_stanford_profile';
  $field_group->mode = 'profile_page';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teaching',
    'weight' => '7',
    'children' => array(
      0 => 'cap_advisees',
      1 => 'cap_coursestaught',
      2 => 'cap_graduateandfellowshipprog',
      3 => 'cap_postdoctoraladvisees',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cap-teaching field-group-fieldset',
      ),
    ),
  );
  $export['group_cap_teaching|node|cap_stanford_profile|profile_page'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cap_teaching|node|cap_stanford_profile|profile_page_tabbed';
  $field_group->group_name = 'group_cap_teaching';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cap_stanford_profile';
  $field_group->mode = 'profile_page_tabbed';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Teaching',
    'weight' => '7',
    'children' => array(
      0 => 'cap_advisees',
      1 => 'cap_coursestaught',
      2 => 'cap_graduateandfellowshipprog',
      3 => 'cap_postdoctoraladvisees',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'id' => '',
        'description' => '',
        'classes' => 'group-cap-teaching field-group-htab',
      ),
    ),
  );
  $export['group_cap_teaching|node|cap_stanford_profile|profile_page_tabbed'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_research_scholarship|node|cap_stanford_profile|profile_page';
  $field_group->group_name = 'group_research_scholarship';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cap_stanford_profile';
  $field_group->mode = 'profile_page';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Research & Scholarship',
    'weight' => '6',
    'children' => array(
      0 => 'cap_clinicalinterests',
      1 => 'cap_clinicaltrialsurl',
      2 => 'cap_currentresearchinterests',
      3 => 'cap_industryrelationships',
      4 => 'cap_labaffiliations',
      5 => 'cap_projects',
      6 => 'cap_researchprojects',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Research & Scholarship',
      'instance_settings' => array(
        'classes' => 'group-research-scholarship field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_research_scholarship|node|cap_stanford_profile|profile_page'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_research_scholarship|node|cap_stanford_profile|profile_page_tabbed';
  $field_group->group_name = 'group_research_scholarship';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cap_stanford_profile';
  $field_group->mode = 'profile_page_tabbed';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Research & Scholarship',
    'weight' => '6',
    'children' => array(
      0 => 'cap_clinicalinterests',
      1 => 'cap_clinicaltrialsurl',
      2 => 'cap_currentresearchinterests',
      3 => 'cap_industryrelationships',
      4 => 'cap_labaffiliations',
      5 => 'cap_projects',
      6 => 'cap_researchprojects',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Research & Scholarship',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-research-scholarship field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_research_scholarship|node|cap_stanford_profile|profile_page_tabbed'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|cap_stanford_profile|profile_page_tabbed';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cap_stanford_profile';
  $field_group->mode = 'profile_page_tabbed';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs group',
    'weight' => '4',
    'children' => array(
      0 => 'group_cap_academic_contact_info',
      1 => 'group_cap_bio',
      2 => 'group_cap_professional',
      3 => 'group_cap_publications',
      4 => 'group_cap_teaching',
      5 => 'group_research_scholarship',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs field-group-htabs',
      ),
    ),
  );
  $export['group_tabs|node|cap_stanford_profile|profile_page_tabbed'] = $field_group;

  return $export;
}
