// ��������Ĺ˿� /d/city/chuzhou/npc/reader.c
// by lala, 1997-12-13

inherit NPC;

void create()
{
    set_name( "����", ({ "shu sheng", "reader" }) );
    set( "gender", "����" );
    set( "age", 25 );
    set( "long", "���Ǹ�������������������������������飬���ǲ���\n" );        

    set("combat_exp",6000);
        set("qi",400);
        set("max_qi",400);
        set("eff_kee",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_sen",400);

    setup();
    carry_object( "/clone/misc/cloth" )->wear();
}

int query_answer()
{
    command( "say ����ѽ�����ô����Ϊ���ıȽϼ�����û��׼����˵ʲô�أ���������˵����" );
    return 1;
}    

