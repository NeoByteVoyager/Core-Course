# design_spec.md — 个人作品集分享 PPT

## I. Project Information
- **project name**: 个人作品集网站分享 PPT
- **deck goal**: 向社团/同学展示个人作品集网站的设计理念、技术实现和项目成果
- **audience**: 社团成员、同学（非专业评委，偏轻松氛围）
- **use case**: 社团技术分享会
- **page range**: 8-12 页
- **language**: 中文为主，英文为辅（技术术语）
- **content basis source**: `content_report.md`
- **identity anchors**: 个人技术分享、开发者身份
- **ratio**: 16:9

## II. Narrative Spine
- **核心叙事**: 我是一个热爱技术的创作者 → 我会什么 → 我做了什么 → 怎么做的 → 未来要做什么
- **故事弧线**: 开场吸引 → 建立信任（技能）→ 展示成果（项目）→ 揭示过程（网站设计）→ 开放结尾（联系/未来）
- **来源**: 继承自 content_report.md 的结构化内容
- **确认状态**: 整体框架 user_provided；具体项目细节部分 inferred，措辞保持克制

## III. Style Direction
- **chosen style proposal**: 方案 B — 极简留白风
- **one-line positioning**: 白底留白 + 少量彩色点缀，干净清爽，投影友好
- **cover direction**: 大面积白色留白，左侧彩色半透明圆点装饰，右侧大号黑体标题 + 灰色副标题
- **body-page visual grammar**: 白色卡片容器 + 细灰边框，关键数字用三色渐变圆角矩形标注，留白充足
- **why this fits**: 社团分享不需要过度设计，极简风格让听众聚焦内容本身，且投影效果最可靠
- **reverse-engineered preview facts**:
  - 白色背景为主，灰色容器框作为信息区域
  - 标题使用深色粗体中文，副标题浅灰
  - 紫色(#6c63ff)、青色(#00d4aa)、粉色(#ff6b9d)三色作为点缀，各占约10%
  - 编号圆点交替使用三色
  - 分割线极细，颜色浅灰
- **user-confirmed liked elements**: 大面积留白、白色卡片容器、彩色百分比标签、编号圆点
- **local-only elements**: 封面左侧的彩色圆点组合仅用于首页，不应扩散到正文页
- **not hard-locked**: 具体的圆点数量和位置仅在首页生效

## IV. Global Design Principles
- **density and rhythm**: 低密度，行间距宽松，每页信息不超过 5 个要点
- **text-visual balance**: 文本主导，装饰元素仅作点缀（<15% 画面）
- **brand constraint level**: 轻量 — 三色体系贯穿，但不过度品牌化
- **image strategy**: 项目页可使用网站截图缩略图；其余以文字 + 简单图形为主
- **background policy**: 全篇白色或极浅灰底色，不出现深色页面

## V. Content Structure
- **section breakdown** (拟 10 页):
  1. 封面 — 个人作品集
  2. 关于我 — 技术探索之旅
  3. 技术栈全景 — 六边形能力图谱
  4. 项目一 — 数据可视化平台
  5. 项目二 — AI 聊天机器人
  6. 项目三 — 开发者工具集
  7. 网站设计 — 理念与结构
  8. 技术实现 — 关键亮点
  9. 未来计划 — 持续探索中
  10. 联系方式 — Q&A
- **emphasis points**: 第 3 页（技能全景）和第 4-6 页（项目展示）是核心
- **uncertain claims**: 项目具体技术细节为 inferred，措辞保持一般性描述

## VI. Preview-to-Deck Continuity
- **extension plan**: 首页的彩色圆点装饰语言 → 转为内页的编号圆点和分割线点缀
- **reverse-engineered from previews**:
  - 白色容器框是主要信息承载体 → 全篇所有正文页使用灰色容器
  - 三色交替编号 → 全篇章节编号沿用紫/青/粉交替
  - 百分比标签用圆角胶囊形状 → 技能/进度类数据统一用此格式
- **must stay consistent**: 白底、灰容器、三色点缀、宽松行距
- **deck-wide anchors**: 三色体系（紫/青/粉）、白色卡片容器、细灰分割线
- **local only**: 封面左侧的彩色圆点群仅用于首页
- **encouraged variation**: 项目页可加入网站截图缩略图；联系页可改用居中布局

## VII. Constraints
- **hard requirements**: 16:9 比例，白底，中文为主
- **things to avoid**: 深色背景、高饱和度大面积色块、拥挤排版、装饰过度
- **post-generation overlay policy**: 零覆盖 — 生成即最终，不做文字叠加
- **unsupported-claim policy**: 不使用精确数据（如"日活1000"）除非用户提供
- **source-grounding policy**: 所有内容源自 content_report.md
