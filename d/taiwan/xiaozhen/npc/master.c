#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("��ڤ��", ({ "dongming zi","dongmingzi","dongming","master" }));

  set("gender", "����");
  set("age", 87);

  set("str", 20);
  set("per", 20);
  set("cor", 30);
  set("cps", 75);
  set("kar", 50);
  set("int", 40);
  set("con", 40);
  set("spi", 40);

  set("long","����˫�ۿտն���,�ƺ���û��ע����,ֻ����
��һת��,���ܿ�����������,��������˿����,
ȫ������ɢ����һ���ɫ��ã.\n");
  set("title", RED+"��ڤɽׯ"+NOR);
        set("shen_type",-1);
  set("nickname",YEL+"����"+NOR);
  set("combat_exp", 2000000);
set_skill("literate",200);
  set_skill("unarmed", 200);
  set_skill("force", 200);

set_skill("blade",200);
set_skill("sword",200);
  set_skill("dodge", 200);
  set_skill("parry", 200);


   set("combat_exp", 9999999);
    set("score", random(90000));
    
         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
	set("qi", 28000);
	set("max_qi", 28000);
	set("jing", 28000);
	set("max_jing", 28000);
	set("neili", 55000);
	set("max_neili", 55000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 600000);
	set("shen", 200000);

  set("inquiry", ([
	"name"    : "������ڤһ�ɳ��϶�ڤ��,������һ��ֻʣ����һ���ˡ�",
	"here"    : "��������,����ô������?��",
	"rumors"  : "��Ϣ���㲻ר��ѧ�գ���������ʲô��Ϣ��",
      "ɱ��":"ֻҪ��ɱ����ʮ����,�Ϸ������������,��һ��������!",
]) );

  create_family(RED+"��ڤɽׯ"+NOR, 3, "����");

  setup();
    carry_object("/d/ghost/npc/obj/cloth3")->wear();
    carry_object("/d/ghost/npc/obj/hat")->wear();
    carry_object("/d/ghost/npc/obj/swordd")->wield();
	add_money("gold",3);
}
int accept_fight(object me)
{
  command("say �ٺ�,�Ϸ��ڴ�������ʮ��,�Ļ��������˵Ļ�����");
  return 0;
}

