 inherit NPC;
void create()
{
        set_name("��Ӱ", ({ "shadow" }) );
        set("gender", "����" );
        set("age", 42);
        set("str",22);
        set("long",
                "�������ǳմ����֮ɫ��Ŀ��Ҳ����ʧȥ�������Ĺ���
�������������Լ�����������ֱҲ�������Լ��Ǹ����ˡ�\n");
        set("combat_exp", 700+random(10000));
        set("chat_chance", 1);
        set("chat_msg", ({
                "��Ӱ����ɨ��ɨ�ŵأ�������\n",
        }) ); 
        set("attitude", "aggrensive");
        setup(); 
}   
