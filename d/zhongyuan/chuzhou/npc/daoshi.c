// ���ݵ�ʿ /d/city/chuzhou/npc/daoshi.c
// by lala, 1997-12-13

inherit NPC;
#include <ansi.h>

int ask_me();
int add_max_age( object ob, object me );

void create()
{
    set_name( "������", ({"yuxu zi", "yuxu", "daoshi"}) );
    set( "gender", "����" );
    set( "age", 82 );
    set( "per", 27 );
    set( "class", "taoist" );
    set( "attribute", "friendly" );
    set( "title", YEL"����"NOR );
    set( "long", @LONG
��������幬�ĵ��ҵ�ʿ���������ӡ����������㣬�ڳ��ݳǴ�������������
���ǵ������Ҳ������˵��������������������ȥ���͸��������ˡ���ͷ�Ρ���
���ڵط��������صĵط���ҲҪ�������֡��������������������������ӵ���
���ﲻ����
LONG
    );
    set("qi",400);
    set("max_qi",400);
    set("eff_kee",400);
    set("sen",400);
    set("max_sen",400);
    set("eff_sen",400);
    set( "positive_score", 10000 );
    set( "negative_score",  3000 );
    set( "combat_exp",    1500000 );

    set( "inquiry", ([
        "����"      :   (: ask_me :),
        "����"      :   (: ask_me :),
        "����"      :   (: ask_me :),
        "����"      :   (: ask_me :),
        "age"       :   (: ask_me :),
        "life"      :   (: ask_me :),
        "max age"   :   (: ask_me :),
        "max_age"   :   (: ask_me :),
    ]));
    setup();
    carry_object( "/clone/misc/cloth" )->wear();

    add_money( "silver", random(5) + 3 );
}

int ask_me()
{
    object me = this_player();
    object ob = this_object();
    object here = environment();
    int age = me->query("age");
    int m_age = me->query("max_age");
    
    if( here->query( "short" ) != WHT"���幬"NOR )
    {
        command( "say �����ô�������ﲻ���㣬���ǵ�ƶ����ȥ��˵�ɡ���" );
        return 1;
    }        
    if( m_age > ( age + 12 ) )
    {
        command( "smile " + me->query( "id" ) );
        command( "say ����λ" + RANK_D->query_respect( me ) 
            + "ӡ�÷��������������˵�����ٻ��������عһ�����" );
        return 1;
    }
    command( "hmm" );
    command( "say ����λ" + RANK_D->query_respect( me )
        + "ӡ�÷��������к��������������겻�������ٽ����˰ɡ���" );
    command( "say �������أ����" + RANK_D->query_respect( me )
        + "���ƺ�ʩ��������£���ôҲ���������������������١���" );
    me->set_temp_marks( "marks/chuzhou/���Ծ��", 1 );
    return 1;
}

int accept_object( object me, object ob )
{
    int age = me->query("age");
    int m_age = me->query("max_age");
    int zhishu = ( m_age + 1 ) / 12;
    int i, money = 5000;
    int value = ob->value();
    
    if( value < 1 )
        return 0;
    if( !me->query_temp_marks( "marks/chuzhou/���Ծ��" ) )
    {
        command( "say ����лʩ�ᣬ��������һ���ᱣ����ġ���" );
        return 1;
    }
    for( i = 1; i < zhishu; i++ )
        money = money * 2;
    money = money * ( 140 - me->query_kar() * 2 ) / 100;         
    if( value < money )
    {
        command( "shake" );
        command( "say ���Ĳ��ϣ��ǲ���õ�����ı��ӵġ���" );
        return 0;
    }
    call_out( "add_max_age", 1, ob, me );
    return 1;
}                    
                           
int add_max_age( object ob, object me )
{
    destruct( ob );
    me->add( "max_age", 1 );
    me->delete_temp_marks( "marks/chuzhou/���Ծ��" );
    message_vision( "$Nȡ��ɰˮˢ��һ���Ʊ���ľ�����ˣ��ڻ���һ�գ����������дǡ�\n", this_object() );
    tell_object( me, "��ͻȻ�о�����Ϊ֮һ�񣬾�����ʢ����ࡣ\n" );
    return 1;
}    
                              
