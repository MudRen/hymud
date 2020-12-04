// Npc: popi.c
//by trill 97-10-29 12:17

#define X_TASK_KILL_XINGHU          ( 1 << 12 )

inherit NPC;

int ask_about_xinghu();

int xinghu;



void create()
{

	set_name("��Ƥ", ({"po pi", "punk"}) );
	set("long", @LONG
һ�����꺺�ӣ����ӽ�Ϊ�������Ĳ��ߣ�һͷ�ҷ������ϵ��·��ƾ�
���ҡ�
LONG
	);
	set( "gender", "����" );
	set( "attitude", "heroism" );

	set( "age", 24 );
	set( "max_kee", 350 );
	set( "qi",350 );
	set( "max_force", 300 );
	set( "force", 300 );
	set( "combat_exp", 8000 );
    set( "inquiry", ([
        "�ϻ�" : (: ask_about_xinghu :),
    ]) );

	setup();

    carry_object(__DIR__"obj/cloth2")->wear();
}

void init()
{
    object ppl;
    int mark;

    ::init();
    
    if ( !( this_object()->can_act() ) ) return;
    ppl = this_player();
    mark = ( int ) ppl->GetMark( "xing" );
    if ( ppl->can_act() )
    {
        if ( ( ppl->query( "positive_score" ) > 5000 )
            && !( mark & X_TASK_KILL_XINGHU ) )
        {
            message_vision( "��Ƥ����$N���������Ҵҵ���ȥ�ˡ�\n", ppl );
            destruct( this_object() );
        }
        else if ( mark & X_TASK_KILL_XINGHU )
        {
            message_vision( "��Ƥ������$N���ƺ���Щ������\n", ppl );
        }
        else if ( ppl->query( "gender" ) == "Ů��" )
        {
            command( "interest " + ppl->query( "id" ) );
        }
    }
}


int ask_about_xinghu()
{
    object ppl = this_player();
    int mark = ( int ) ppl->GetMark( "xing" );
    if ( ( mark & X_TASK_KILL_XINGHU ) && xinghu )
    {
        message_vision( "��Ƥ��$N˵���������ϴ󰡣��������е�С�����档\n", ppl );
        xinghu = 0;
    }
    else 
    {
        message_vision( "��Ƥ˵���������ϴ������û���Ҳ�֪�������\n", ppl );
    }
    return 1;
}

void setup()
{
    ::setup();
    xinghu = 1;
}
