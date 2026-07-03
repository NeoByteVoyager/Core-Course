# slide_blueprint.md — 个人作品集分享 PPT 页面蓝图

---

## S01 封面
- page_role: cover
- title: 个人作品集
- core_message: 建立第一印象 — 技术创作者的身份
- content_payload: 主标题"个人作品集" + 副标题"我的技术探索与创造之旅" + 身份标签
- content_basis_binding: content_report.md 主题与核心信息
- claim_status: user_provided
- page_rhythm: atmospheric
- text_visual_balance: text-dominant with decorative accents
- visual_strategy: 白色背景，左侧三彩色半透明圆点装饰，右侧大号中文标题 + 灰色副标题 + 英文身份标签 + 底部紫色细线
- continuity_inheritance: 白底、三色点缀（紫/青/粉）、宽松留白
- preview_evidence_binding: 继承首页预览的左侧彩色圆点 + 右侧标题布局；圆点位置可微调

---

## S02 关于我
- page_role: logic
- title: 关于我 — 技术探索之旅
- core_message: 我是谁，我的技术理念和兴趣方向
- content_payload: 个人简介段落 + 3-4 个兴趣方向标签
- content_basis_binding: content_report.md "我是谁" 部分
- claim_status: user_provided（简介）+ inferred（兴趣方向具体表述）
- page_rhythm: narrative
- text_visual_balance: text-dominant
- visual_strategy: 白色背景，灰色圆角卡片容器承载自我介绍文字，底部三个彩色标签胶囊（紫/青/粉）标注兴趣方向
- continuity_inheritance: 白底、灰卡片容器、三色标签
- preview_evidence_binding: 继承正文预览的白色卡片容器语法；编号圆点转为标签圆角胶囊

---

## S03 技术栈全景
- page_role: data
- title: 技术栈全景 — 六边形能力图谱
- core_message: 展示 6 大技术方向及熟练度
- content_payload: 6 项技能卡片（前端85%/后端75%/数据AI70%/数据结构80%/设计65%/工具78%）
- content_basis_binding: content_report.md "技术栈" 表格
- claim_status: user_provided（技能名称和百分比）
- page_rhythm: structured grid
- text_visual_balance: balanced
- visual_strategy: 白色背景，灰色容器内 2×3 网格排列 6 张技能小卡片，每张含图标emoji + 名称 + 技术列表 + 底部渐变进度条 + 右侧百分比标签
- continuity_inheritance: 白底、灰容器、三色进度条和百分比标签
- preview_evidence_binding: 直接继承正文预览的技能卡片网格布局 + 百分比标签格式

---

## S04 项目一 — 数据可视化平台
- page_role: showcase
- title: Project Alpha — 交互式数据可视化平台
- core_message: 第一个代表作项目的功能和技术亮点
- content_payload: 项目名称 + 一句话描述 + 技术栈标签（React/D3.js/WebSocket）+ 核心功能点 2-3 条
- content_basis_binding: content_report.md "三个代表作项目" 第一条
- claim_status: inferred（功能描述基于项目名和技术栈推断，措辞一般性）
- page_rhythm: card + list
- text_visual_balance: balanced
- visual_strategy: 白色背景，顶部灰色卡片展示项目缩略图占位区（渐变色块 + 项目emoji），下方白色卡片列出技术标签和功能要点，紫色圆点编号
- continuity_inheritance: 白底、灰容器、紫色编号、宽松行距
- preview_evidence_binding: 继承编号圆点颜色交替（本项目用紫色）；卡片容器语法

---

## S05 项目二 — AI 聊天机器人
- page_role: showcase
- title: AI Chat Bot — 智能对话系统
- core_message: 第二个代表作 — AI 方向的实践
- content_payload: 项目名称 + 描述 + 技术栈标签（Python/NLP/FastAPI）+ 核心功能点 2-3 条
- content_basis_binding: content_report.md 第二条项目
- claim_status: inferred
- page_rhythm: card + list
- text_visual_balance: balanced
- visual_strategy: 同 S04 布局，青色编号圆点，项目缩略图用青色渐变底色
- continuity_inheritance: 白底、灰容器、青色编号交替
- preview_evidence_binding: 继承项目页卡片布局；编号颜色按紫/青/粉交替规律

---

## S06 项目三 — 开发者工具集
- page_role: showcase
- title: Dev Toolkit — 开发者效率工具集
- core_message: 第三个代表作 — 工程实践
- content_payload: 项目名称 + 描述 + 技术栈标签（Node.js/Electron/TypeScript）+ 核心功能点 2-3 条
- content_basis_binding: content_report.md 第三条项目
- claim_status: inferred
- page_rhythm: card + list
- text_visual_balance: balanced
- visual_strategy: 同 S04/S05 布局，粉色编号圆点，项目缩略图用粉色渐变底色
- continuity_inheritance: 白底、灰容器、粉色编号交替
- preview_evidence_binding: 继承项目页卡片布局；编号颜色交替规律

---

## S07 网站设计 — 理念与结构
- page_role: logic
- title: 网站设计 — 理念与结构
- core_message: 个人作品集网站的设计思路和页面结构
- content_payload: 设计理念（好设计+优雅代码=打动人心的产品）+ 5 个页面模块说明（Hero/About/Skills/Projects/Contact）
- content_basis_binding: content_report.md "网站特色" + 整体结构
- claim_status: user_provided（设计理念）+ inferred（模块说明）
- page_rhythm: structured
- text_visual_balance: text-dominant
- visual_strategy: 白色背景，灰色容器内分两列：左列设计理念文字，右列 5 个模块名称用彩色标签胶囊列出（紫/青/粉交替），底部一条紫色渐变分割线
- continuity_inheritance: 白底、灰容器、三色标签
- preview_evidence_binding: 继承正文预览的卡片容器语法；彩色标签延续编号圆点的三色交替

---

## S08 技术实现 — 关键亮点
- page_role: data
- title: 技术实现 — 关键亮点
- core_message: 网站背后的技术亮点
- content_payload: 4 个技术亮点（粒子网络背景/打字机动画/滚动渐入/毛玻璃导航）各一行描述
- content_basis_binding: content_report.md "网站特色" + index.html 技术细节
- claim_status: user_provided（技术名称）+ inferred（描述措辞）
- page_rhythm: structured list
- text_visual_balance: balanced
- visual_strategy: 白色背景，灰色容器内 2×2 网格排列 4 个技术亮点卡片，每个卡片含图标 + 标题 + 简短描述，卡片四角分别用紫/青/粉/紫小圆点标记
- continuity_inheritance: 白底、灰容器、三色点缀
- preview_evidence_binding: 继承卡片网格语法；圆点标记延续三色交替

---

## S09 未来计划
- page_role: narrative
- title: 未来计划 — 持续探索中
- core_message: 接下来的学习方向和成长规划
- content_payload: 3-4 个未来方向（通用描述，不编造具体目标）
- content_basis_binding: inferred from content_report.md "持续探索"基调
- claim_status: inferred（方向为合理推测，非精确承诺）
- page_rhythm: narrative
- text_visual_balance: text-dominant
- visual_strategy: 白色背景，居中布局，灰色圆角卡片容器，内部 3-4 条方向用箭头符号引导，每条前缀一个彩色圆点（紫/青/粉交替）
- continuity_inheritance: 白底、灰容器、三色圆点
- preview_evidence_binding: 继承三色圆点编号语法；布局比正文页更宽松

---

## S10 联系方式
- page_role: closing
- title: 联系我 — 感谢聆听
- core_message: 开放合作与交流，Q&A
- content_payload: 一句邀请语 + 4 个联系方式（Email/GitHub/LinkedIn/Twitter）
- content_basis_binding: content_report.md "联系方式"
- claim_status: user_provided（联系渠道名称）；具体链接待用户补充
- page_rhythm: centered
- text_visual_balance: balanced
- visual_strategy: 白色背景，居中布局，大号"感谢聆听" + 邀请语，下方 4 个彩色边框按钮（Email-紫/GitHub-青/LinkedIn-粉/Twitter-紫），底部一条三色渐变横线
- continuity_inheritance: 白底、三色体系、宽松留白
- preview_evidence_binding: 继承三色体系；按钮样式为新增，但延续圆角胶囊语法
