/* waiter.c
 * from XO Lib
 * a npc of gaochang
 * copied from lanzhou 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */


inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name( "�販ʿ", ({ "cha boshi", "waiter" }) );
    set( "gender", "����" );                //�Ա���
    set( "age", 22 );                       //���䣺22
    set( "attitude", "friendly" );          //̬�ȣ�����
    set( "rank_info/respect", "��ү��" );   
    set( "long", @LONG
    �販ʿ�������һ���裬Ц���е���������Ʒ����
LONG
    );


    set( "combat_exp",  7500 );             //ս�����飺7500

	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));

    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //�಼����
}

void init()
{
    object ppl;

    ::init();

	add_action("do_buy", "buy");
	add_action("do_list", "list");

    if ( !userp( ppl = this_player() ) 
        )
        return;
    remove_call_out( "Greeting" );
    call_out( "Greeting", 1, ppl );
}

void Greeting( object ppl )
{
    if ( !ppl 
        || environment( ppl ) != environment() ) 
        return;
     command( "say ��λ" + RANK_D->query_respect( ppl ) + "�������ȿڲ裬"
"ЪЪ�Ȱɡ���\n");
}



