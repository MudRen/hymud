 inherit NPC;
void create()
{
        set_name("��ʦ", ({ "chef" }) );
        set("gender", "����" );
        set("age", 43);
        set("long", "һ���������Ĵ����\n");
        set("combat_exp", 1000000);
        set("neili", 500);
        set("attitude", "friendly");
        set("max_neili", 500);
        set("force_factor", 12);
        set_temp("apply/attack", 150);
        set_temp("apply/dodge",150);
  
  
        set("inquiry", ([
                "ԭ��" : "�ղ˵�ԭ�ϲ��������ϰ����������˰�æ�ء�",
                "ɽȸ��": "֪���һ�Ҫ���æ��",
                "��ɽ����": "֪���һ�Ҫ���æ��",
                "ɳ���": "֪���һ�Ҫ���æ��",
                "����": "֪���һ�Ҫ���æ��",
        ]));      
        set("chat_chance", 1);
        set("chat_msg", ({
                "�������䤱���æ���ղˣ���ζ���硣����\n",
                "���̾����˵��ԭ�ϲ�ȫ���ɸ���Ϊ����֮������\n",
        }) );
        setup();
        carry_object(__DIR__"obj/apron")->wear();
}
