// kid.c    С��
// Ffox 98-4-30 14:14
inherit NPC;

void create()
{
    set_name( "С��", ({ "xiao hai", "xiaohai", "hai", "kid"  }) );
    set( "gender", "����" );                //�Ա���
    set( "age", 9 );                
    set( "long", @LONG
�����ˡ������ˡ�����
LONG );
    set( "attitude", "friendly" );
    set( "inquiry", ([
    "�˵�" : "��֪������������",
]) );
    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //�ֲ���
}

