#include <ansi.h>
inherit NPC;
void create()
{
        set_name("������", ({ "wu liupo","wu","liupo"}) );
        set("long",@LONG
�����ݱ�ֱ����Ȼͦ��������һ���������ҵ����ʣ��԰׵�������Ũ�ҵ�
�����������ȥ�����࣬������ƫ�Ѱ��ԣ������������߸�����¶��ѩ��
���ֱۣ���ʮָ�ⳤ����ʤŮ�����ҵ��֡�����ʹ��עĿ������������Ю��һ
�������������������롣
LONG
         );

        set("title",MAG"�������"NOR);
       set("nickname","ɢ����");
        set("max_jing", 9000);
        set("max_qi", 9000);                    
        set("max_sen", 9000);
        set("max_neili",9000); 
        set("neili",6000);
        set("jiali",180);     
        set("combat_exp",4500000);
        set("cor",100);
        set("age",65);

        set_skill("force", 400);
        set_skill("huagong-dafa", 480);
        set_skill("dodge", 480);
        set_skill("zhaixinggong", 410);
        set_skill("unarmed", 450);
        set_skill("chousui-zhang", 400);
        set_skill("parry", 450);
        set_skill("staff", 470);
        set_skill("tianshan-zhang", 415);
        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("unarmed", "chousui-zhang");
        map_skill("parry", "tianshan-zhang");
        map_skill("staff", "tianshan-zhang");
        set_temp("apply/attack",50);
        setup();
}
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player())) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
         if(random(15) < 2)
                this_object()->set_leader(ob);
        }
}

