// ����С��ʿ /d/city/chuzhou/npc/daoshi2.c
// by lala, 1997-12-13

inherit NPC;

void create()
{
    set_name( "������", ({ "yunqing zi", "yunqing", "daoshi" }) );
    set( "title", "��ʿ" );
    set( "gender", "����" );
    set( "class", "taoist" );
    set( "age", 20 );
    set( "per", 25 );
    set( "long", "���Ǹ�����ĵ�ʿ���������ӵ�ͽ�ܣ�������Ҽ�����û����˵����ʲô��\n" );        
    set( "inquiry", ([
        "������"    : "�������ҵ�ʦ�����������˼ҵı��¿ɴ��ˣ����϶����˼������ϡ���",
        "here"      : "������ǳ��ݺպ����������幬���㲻֪���𣿡�",
    ]));            
        set("qi",400);
        set("max_qi",400);
        set("eff_kee",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_sen",400);

    set("combat_exp",6000);

    setup();
    carry_object( "/clone/misc/cloth" )->wear();

}

