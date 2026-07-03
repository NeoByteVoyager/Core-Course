# spec_lock.md — 执行约束锁定

## canvas
- format: PPT slide image
- ratio: 16:9
- size: 1024x576

## visual_system
- chosen_style_direction: 方案 B — 极简留白风
- reverse_engineered_preview_facts:
  - 白色背景为主，极浅灰(#fafafa)容器框承载信息
  - 标题使用深色粗体中文(#1a1a2e)，副标题灰色(#666/#999)
  - 三色点缀：紫色#6c63ff / 青色#00d4aa / 粉色#ff6b9d，各占约10%
  - 编号圆点交替使用三色
  - 细灰分割线(#f0f0f0/#eee)
  - 圆角胶囊形状的百分比/标签
- deck_wide_liked_elements:
  - 白色背景 + 灰色容器框
  - 三色交替编号圆点
  - 宽松行距和大面积留白
  - 圆角胶囊标签
- deck_level_continuity_anchor:
  - brightness_world: high-key bright
  - background_tendency: pure white or near-white (#ffffff / #fafafa)
  - forbidden_dark_pages: no dark backgrounds anywhere in the deck
  - lighting_model: flat, even, no shadows or glows
  - material_language: clean white panels with subtle borders
  - container_grammar: rounded rectangles with thin light-gray borders
  - decoration_grammar: small colored circles (purple/teal/pink alternating), thin accent lines
  - emphasis_tone: clean, readable, uncluttered
- cover_body_continuity_rules: same white background, same gray container, same three-color accent system
- allowed_variation_range: cover may have larger decorative circles; data pages may use 2x3 grids; closing page may center-align; full dark pages forbidden
- fixed_brightness_range: #ffffff to #fafafa only

## colors
- dominant: white (#ffffff) background, light gray (#fafafa / #f5f5f5) containers
- structure: deep charcoal (#1a1a2e) for main titles
- secondary: medium gray (#666 / #999) for subtitles and body text
- accent_1: purple (#6c63ff) — primary accent
- accent_2: teal (#00d4aa) — secondary accent
- accent_3: pink (#ff6b9d) — tertiary accent
- accent_usage: each accent color used for less than 15% of any single slide area
- divider: very light gray (#f0f0f0 / #eee)

## typography
- title_font: PingFang SC / Microsoft YaHei / sans-serif, bold, large
- subtitle_font: same family, regular or light, medium
- body_font: same family, regular, comfortable line-height (1.6+)
- english_text: Segoe UI / sans-serif, smaller size
- no decorative fonts, no handwriting styles

## rhythm
- global_density: low — generous whitespace around all elements
- max_items_per_slide: 5 content items maximum
- line_spacing: loose (1.6+)
- card_padding: ample (20px+ inside containers)
- inter-card_gap: 16px+

## brand_constraints
- level: light
- mandatory: three-color accent system (purple/teal/pink) must appear somewhere on every slide
- mandatory: white background on every slide
- mandatory: rounded rectangle containers for grouped content
- flexible: specific accent color assignment per slide
- not_mandatory: no external brand logo or identity required

## content_grounding
- content_basis_source: content_report.md
- allowed_claims: skill categories and percentages, project names and tech stacks, personal philosophy statement
- forbidden_claims: specific metrics (users, stars, revenue), experiment results, citations, rankings
- uncertain_claim_policy: use general descriptive language for inferred project details
- preview_content_policy: preview images contain real content from content_report.md, not placeholders

## forbidden
- no dark backgrounds (forbidden everywhere)
- no high-saturation large color blocks (>15% of slide)
- no crowded/dense layouts
- no decorative overload (keep decoration <15%)
- no unsupported precise statistics or numbers not in content_report.md
- no post-generation text overlays (generate = final)
- no cover-only decorative circle clusters carried into body pages
- no placeholder text like "在此输入..." or "title here"

## generation_metadata
- slide_ids: S01-S10 (10 slides)
- filename_pattern: {slide_id}_{short_title}.png
- slide_identifiers_outside_prompts: yes — IDs used for mapping only, not in image generation prompts
- total_slides: 10
