//change.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
           set_name(HIM"֯Ů"NOR, ({"zhi nu", "zhinu", "xian"}));
       set("long",
"����ĸ������Ů����Ϊ˽���·���ţ���మ������������������\nֻ��ÿ������³��߲���ȵ����ᡣ\n");
       set("gender", "Ů��");
       set("age", 20);
       set("class", "xian");
        set("title", "");
       set("attitude", "friendly");
       set("rank_info/respect", "�ɹ�");
       set("per", 30);
	set("int", 30);
         set("max_qi", 1500);
         set("max_gin", 1500);
         set("max_jing", 1500);
         set("neili", 1200);
         set("max_neili", 1200);
       set("force_factor", 50);
         set("max_mana", 1200);
         set("mana", 1200);
         set("mana_factor", 80);
         set("combat_exp", 800000);
    set("daoxing", 2000000);


   set_skill("dodge",300);
        set_skill("cuff",320);
        set_skill("unarmed",300);
        set_skill("parry",300);
        set_skill("blade",380);
         set_skill("feitian-yujianliu",380);
         set_skill("wuxing-dun",380);
        set_skill("shayi",380);
         set_skill("aikido",380);
         set_skill("shayi-xinfa",380);
        set_skill("shiren-jianfa",380);
        set_skill("shiren-quanfa",380);
        set_skill("force",300);
set_skill("huoxinliu-jianfa",380);

        set_skill("literate",250);
        map_skill("blade", "feitian-yujianliu");
        map_skill("force", "shayi-xinfa");
              map_skill("unarmed", "aikido");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");

         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
                (: perform_action, "blade.tianxiang" :),
                (: perform_action, "blade.longlianda" :),
                (: perform_action, "blade.suodi" :),
                (: perform_action, "blade.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
        }));
       set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);

create_family("�¹�", 2, "����");
setup();

             carry_object(__DIR__"obj/luoyi")->wear();
             carry_object(__DIR__"obj/rose")->wear();
       carry_object(__DIR__"obj/yangdao")->wield();
}

