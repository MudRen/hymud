// Npc: popi.c
//by trill 97-10-29 12:17

#define X_TASK_KILL_XINGHU          ( 1 << 12 )

inherit NPC;

int ask_about_xinghu();

int xinghu;



void create()
{

	set_name("泼皮", ({"po pi", "punk"}) );
	set("long", @LONG
一个中年汉子，样子较为猥琐，身材不高，一头乱发，身上的衣服破旧
脏乱。
LONG
	);
	set( "gender", "男性" );
	set( "attitude", "heroism" );

	set( "age", 24 );
	set( "max_kee", 350 );
	set( "qi",350 );
	set( "max_force", 300 );
	set( "force", 300 );
	set( "combat_exp", 8000 );
    set( "inquiry", ([
        "邢虎" : (: ask_about_xinghu :),
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
            message_vision( "泼皮见到$N的来到，匆匆的离去了。\n", ppl );
            destruct( this_object() );
        }
        else if ( mark & X_TASK_KILL_XINGHU )
        {
            message_vision( "泼皮打量了$N，似乎有些不安。\n", ppl );
        }
        else if ( ppl->query( "gender" ) == "女性" )
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
        message_vision( "泼皮对$N说到：我们老大啊，在密林中的小屋里面。\n", ppl );
        xinghu = 0;
    }
    else 
    {
        message_vision( "泼皮说道：我们老大神出鬼没，我不知道在哪里。\n", ppl );
    }
    return 1;
}

void setup()
{
    ::setup();
    xinghu = 1;
}
