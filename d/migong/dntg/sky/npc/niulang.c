//change.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
           set_name(HIG"ţ��"NOR, ({"niu lang", "niulang", "lang"}));
       set("long",
"ԭ���Ǹ���ţ�ޣ�����֯Ů�మ������һ˫��Ů���󱻷�����������\nֻ��ÿ������³��߲���ȵ����ᡣ\n");
         set("gender", "����");
       set("age", 20);
       set("class", "xian");
        set("title", "");
       set("attitude", "friendly");
       set("per", 30);
	set("int", 30);
           set("max_qi", 1000);
           set("max_gin", 1000);
           set("max_jing", 1000);
           set("neili", 1000);
          set("max_neili", 1000);
        set("force_factor", 50);
          set("max_mana", 500);
          set("mana", 500);
           set("mana_factor", 0);
          set("combat_exp", 600000);
     set("daoxing", 500000);


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

              carry_object(__DIR__"obj/linen")->wear();
        carry_object(__DIR__"obj/yuandao")->wield();
}

