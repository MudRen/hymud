/* waiter.c
 * from XO Lib
 * a npc of gaochang
 * copied from lanzhou 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */


inherit NPC;
inherit F_DEALER;


void create()
{
    set_name( "��С��", ({ "xiao er", "xiaoer", "waiter" }) );
    set( "gender", "����" );                //�Ա���
    set( "age", 22 );                       //���䣺22
    set( "attitude", "friendly" );          //̬�ȣ�����
    set( "rank_info/respect", "С����" );   //���ƣ�С����
    set( "long", @LONG
    ��С�����಼��������Ц���еؿ����㣬�����˻����ⷿ��
LONG
    );


    set( "combat_exp",  7500 );             //ս�����飺7500

    set( "inquiry", ([
        "�ⷿ"      :   "�����͹�Ҫ�ⷿ���ã�һ���������ӡ�",
        "ס��"      :   "�͹���Ҫ�ⷿ�ɣ�",
    ]) );
    set( "talk_msg", ({
        "��ס��һ���������ӣ��ܱ����˲ư�ȫ����",
    }) );

	set("vendor_goods", ({
		"/d/xingxiu/npc/obj/yangrou",
		"/d/lanzhouchen/npc/obj/paomo",
		"/d/city/npc/obj/jiudai",
		"/d/lanzhou/npc/obj/jiouhulu",
		"/d/lanzhou/npc/obj/maoniurou",
	}));

    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //�಼����
}

void init()
{
    object ppl;

    ::init();

        add_action("do_list", "list");
        add_action("do_buy", "buy");

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
    switch( random( 3 ) ) 
    {
        case 0:
            say( "��С��Ц�����˵��������λ" + RANK_D->query_respect( ppl )
                + "������ЪЪ�Ȱɡ��������ס���ģ���\n");
            break;
        case 1:
            say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵��������λ" 
                + RANK_D->query_respect( ppl ) + "������ʲô����\n");
            break;
        case 2:
            say( "��С���е������ճ�����С�����Ӱ���Ƥ���ڶ࣬�͹�Ҫ��Ҫ��һ�㣿��\n" );
            break;
    }
}

int accept_object( object ppl, object obj )
{
    if ( obj->value() >= 5000 ) 
    {
        message_vision( "��С������Ǯ��Ц���е�˵�����ͷ���¥�ϣ�������"
            + "�Ϳ�����ȥ�ˡ���\n", ppl );
        ppl->set_temp( "hydra/gaochang/ס��", 1 );
        return 1;
     } 
     return 0;
}

