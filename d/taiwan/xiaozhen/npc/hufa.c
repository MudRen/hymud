#include <ansi.h>
inherit NPC;
void do_kneel();
string *words=({
	"ȫ�ܵ�ʪ����... ...\n",
	"��Ը�����ȫ���������׸�ʪ��,�׸���ڤһ��.\n",
	"ȫ�ܵ�ʪ����,��������ʵ����ͽ...\n",
	"��ʪ����������,������ڤһ��.\n",
     });
void create()
{
    set_name("����",({"hufa"}));
    set("gender","����");
	set("shen_type",-1);
    set("age",46);
    set("title",RED"��ڤɽׯ"NOR);
    set("combat_exp",200000);
    set("kee",500);
    set("max_kee",500);
    set("force",500);
    set("max_force",500);
    set("force_factor",15);
    set("food",200);
    set("water",200);
    
    set("inquiry",([
    "��ڤɽׯ":"�����ڴ��ĵط������ˡ�\n",
    "������ħ��":"���������ϴ󷨣���ϧ�缸����ʧ����.\n",
    ]));
    
    set("chat_chance",3);
    set("chat_msg",({
    (:do_kneel:),
    }));
    
    set_skill("dodge",40);
    set_skill("parry",40);
    set_skill("unarmed",40);
    set_skill("force",40);
    set_skill("literate",20);
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
  
    setup();
    add_money("silver",10);
 }
void do_kneel()
{
  int i;
  object *ob,env;
  string word;
   env=environment(this_object());
   ob=all_inventory(env);
   if (env->query("short")!="�޴�ɽ��") return;
   word=words[random(sizeof(words))];
   command("say "+word);
   for (i=0;i<sizeof(ob);i++)   {
   	if (ob[i]->query("id")=="mentu")
	call_other(ob[i],"say_some",word);
  }
return;
}
   
