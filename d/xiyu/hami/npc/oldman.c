// oldman ����
// Ffox 98-4-25 17:26


inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name( "����", ({ "lao ren", "laoren", "waiter" }) );
    set( "gender", "����" );                //�Ա���
    set( "age", 60 );                       //���䣺22
    set( "attitude", "friendly" );          //̬�ȣ�����
    set( "rank_info/respect", "���˼�" );   //���ƣ�С����
    set( "long", @LONG
���˼��������ͣ��Լ�������ά���ſ��������ơ�
LONG );

    set_skill( "unarmed",  100 );  //ȭ����Ϊ��    �㼶
    set( "combat_exp",  7500 );             //ս�����飺7500
    set( "talk_msg", ({
     "�����ﲻ�Ǿ����������ģ�һ��͸�����ɽ����ż����������һ����������",
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
    if ( !userp( ppl = this_player() ) )
        return;
    remove_call_out( "Greeting" );
    call_out( "Greeting", 1, ppl );
}

void Greeting( object ppl )
{
    if ( !ppl || environment( ppl ) != environment() ) 
        return;
    switch(random(3)){
    case 0:
     message_vision("���˶�$N˵��������λ"+RANK_D->query_respect( ppl )+"�����������������ػ���Ҫ�ȵ�ƣ���\n",ppl);
     break;
    case 1:
     message_vision("���˶�$N���˵�ͷ�����Ǵ��˸��к���\n", ppl);
     break;
    case 2:
     message_vision("����˵��������λ"+ RANK_D->query_respect( ppl )+"����һ������ô����\n",ppl);
     break;
    default:
     break;
    }
}

