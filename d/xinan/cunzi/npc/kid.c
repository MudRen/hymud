//Writen by lnwm (May.28.1997)
//kid.c

inherit NPC;

void create()
{
        set_name("С�к�", ({ "little kid","kid" }) );
        set("gender", "����" );
        set("age", 14);
        set("long",
"һ��������С�к���������·�����²����������������͡�\n"
        );
        set("combat_exp", 200);

//        set("inquiry", ([
//        ]) );
        set("talk_limit",([
           "social_exp" : 500,
        ]));
        set("talk_msg",({
"С�к����������˵����ô������в���ʶ��������\n",
        }) );
        set("talk_fail_msg",({
"С�к���������һ��С�˵���״��\n",
"С�к�̧ͷ����һ���㣬�ֵ�ͷ���Լ��������͡�\n",
        }));        
        setup();
        carry_object(__DIR__"obj/cloth1")->wear();
}






