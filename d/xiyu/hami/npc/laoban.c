// laoban.c     �ϰ���
// Ffox 98-4-30 14:14
inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name( "�ϰ���", ({ "laoban niang", "laoban"  }) );
    set( "gender", "Ů��" );
    set( "age", 30 );                
    set( "long", @LONG
�����ˡ���������Ϊ������
LONG );
    set( "attitude", "friendly" );
    set( "inquiry", ([
    "����" : "�������ǣ�����ԩ�ң���ô������Ҷ�ȥ�ˡ�",
    "��Ϣ" : "��������Ϣ����һ���������ӡ�",
]) );

	set("vendor_goods", ({
		"/d/xingxiu/npc/obj/yangrou",
		"/d/lanzhouchen/npc/obj/paomo",
		"/d/city/npc/obj/jiudai",
		"/d/lanzhou/npc/obj/jiouhulu",
		"/d/lanzhou/npc/obj/maoniurou",
	__DIR__"obj/putao_jiu",
	}));
    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //�ֲ���
}

void init()
{
    object ppl;
    ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
    call_out( "do_listen", 1 ,ppl );
}

void do_listen()
{
    write("Ů�ϰ����ߺ�ȵ���Զ���ǿ�����һ�㱾�صľưɡ�\n");
}

int accept_object(object me, object ob)
{
    if( ob->value() >= 5000 ){
      command("say ����ͽ�ȥ��Ϣ��...... ");
      me->set_temp("hami/sleep", 4);
      }
    else command("say ƽ���޹ʵظ��Ҷ��������Ҿ�Ц���ˡ�");
    return 1;
}

