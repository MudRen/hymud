 // acao.c
inherit NPC; 
#include <ansi.h>
void create()
{
        set_name("����", ({ "a cao","cao" }) );
        set("gender", "Ů��" );
        set("age", 21);
        set("title","����"+HIG" ����̿�"NOR);
        set("long", HIC "\n�����ü�������������˫�۾����ĵ�ֱ���Թ��˻��ǡ�\n"+
        "����ɫ��Ө����ӳ���ں�����֮�£��������ɷ��\n"+
        "������ȻһЦ�����������·����۲���ת֮�䣬\n"+
        "���һ����������飬�������м����ľ��硣\n" NOR);
        set("chat_chance", 5);
        set("chat_msg", ({
            "��������һЦ�������ݵĵ��죿���ǰ�ˮ�Ľ��죿\n",
            "���ݴ��˸���Ƿ������������סӣ��С�ڣ��������������ˡ�\n",
            "���ݺ�Ȼݸ��һЦ��: ��ˮ�������Ҫ��ɱ˭�أ�\n",
            "�������ĵ������־̾��: ����һ���ˣ���û��˼��\n",
            "�������������һ���С�֣������°�˵: ˭�����˵˵��?\n",
            "����ն��������˵: �ţ�˭Ҫ���۸��ң��Ҿ���������\n", 
          }) );
        set("combat_exp", 2000000);
        set("attitude", "friendly");
        set("per",100);
        set("str", 100);
        set("force",2000);
        set("max_neili",2000);
        set("force_factor",150);
        set_skill("dodge",300);
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
                "��������̾���������������Ǻο���?\n",
                (: command("say ���кλ����������? ����ͳ�ȫ����ɡ�\n") :),
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

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/loulan/obj/blade")->wield();
} 
/*void die()
{
        object ob;
        //command("cry");
        message_vision("\n$N����һ������˵�������Ի�Ϊ�ұ���ġ�\n", this_object());
        message_vision("$N˵�꣬����һ������ȥ��\n", this_object());
        //this_object()->move("/d/fy/church");
        //create();
        destruct(this_object());
}*/
