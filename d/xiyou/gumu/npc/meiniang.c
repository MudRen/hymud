//��ԯ��Ĺ����ʦ��
inherit NPC;
inherit F_SAVE; 
#include <ansi.h>
inherit F_MASTER;
int rank_me();
#include <ansi.h>

void create()
{
       set_name("������", ({"hu meiniang", "hu", "meiniang","master"}));
       set("long",
"ԭ����һֻС���꣬������������ڻ�������\n");
       set("title", "С���꾫");
       set("gender", "Ů��");
       set("age", 18);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("rank_info/respect", "���");
       set("per", 40);
        set("int", 30);
       set("max_kee", 500);
       set("max_gin", 500);
       set("force", 500);
       set("max_force", 500); 
       set("force_factor", 20);
       set("max_mana", 300);
       set("mana", 300);
       set("mana_factor", 20);
       set("combat_exp", 200000);
  set("daoxing", 100000);


        set("eff_dx", 70000);
        set("nkgain", 260);


create_family("��ԯ��Ĺ", 3, "����");
setup();

        
      //  carry_object("/d/moon/obj/guihuajian")->wield();
}

