#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��å��", ({ "rabbit" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", 
"һֻ��β�͵�Ұ�ã�β��һ��һ�̵ġ�\n");
        set("max_qi", 1000);
        set("env/wimpy", 99);
        set("maze_get",1);
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) ); 
        set("death_msg",YEL"\n��å������һ�գ��ȶ�һ�ţ�ֱͦͦ���ɵ��ϡ������� \n"NOR);
        set("self_go_msg",1);
        set("arrive_msg","��å�ñı����������˹�����");
        set("leave_msg","��å��һ���Ӵ�û�ˡ�");
 set("vendetta/authority",1);
        set_skill("dodge", 1000+random(1000)); 

        set("maze_item",1);
        setup();
} 
