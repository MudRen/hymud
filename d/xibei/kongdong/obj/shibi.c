// shibi.c writen by cry 10.1.98

#include <ansi.h>
private int gain_points( object me );
private int gain_xiuwei( object me );
inherit ITEM;
int look_item(string arg);


void create()
{
	set_name(HIC"ʯ��"NOR, ({ "shibi" }) );
        set_weight(200000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ��ʯ�ڣ���������羵������д�����ŵ�����С��. \n");
		set("unit", "��");
		set("no_get",1);
		set("value",1000);
		set("material", "stone");
	}
	setup();
}

void init()
{
    add_action("can_xiu", "canxiu");
}

int can_xiu( string arg )
{
    object me;
    me = this_player();
    if ( me->query("marks/kongdong/dao")!=2)
      return notify_fail(HIB"������ô�����ģ�ȥ���ɣ��Ǻǣ��Ż���ģ��´ΰ��չ�ؽ�����\n"NOR);
    if( !me->can_act() || me->is_fighting() )
        return notify_fail(HIB"�������Ķ�����˼ȥ�о����ʯ���ϵĶ�����\n"NOR); 
    tell_object( me, WHT"�����ʯ�ڣ�Ǳ�ĵ��о�������\n"NOR);
    me->disable_command("verb", HIB"һ�����ܶ��ã�? ��\n"NOR);
    call_out("start_canxiu", 10, me );
    return 1;
}

void start_canxiu( object me )
{
    int time;
    if( !me ) return;
    if( me->query_xiuwei_by_type("blade") < 5300 )
    {
        me->enable_path();
        me->receive_damage("gin", 50 );
        tell_object( me, YEL"��Ī�������ʯ������Щ��ʽ��ֻ������յ����ġ�\n"NOR);
        return;
    }
    if (!me->query_jibie("huoyan-dao"))
    {           me->enable_path();      
        me->improve_jibie("huoyan-dao", 1);
            tell_object( me, WHT"���Ȼ�����һ�������������������\n"NOR
                             HIM"��ġ����浶�������ˣ�\n" NOR);
             return;
        }
    tell_object( me, WHT"�������ıȻ�����ǽ�ϵ�С�˶�ͼ�Σ�����ͻȻ���һ��\n"
                    WHT"���˼���У��þò���......\n"NOR);
    me->set_temp("block_msg/all", 1);
    time = 30 ;
    call_out("get_gain", time, me );
}

void get_gain( object me )
{
    string msg;
    int point;

    if( !me ) return;

    me->delete_temp("block_msg/all");

    msg = CYN"��֪��������ã���Ŵӳ�˼���������������Ź���������\n"NOR;
    if ( me->query_lingwu_ratio( "huoyan-dao" )<90)
    {       point=0;
            msg += WHT"ֻ�е�ʯ���ϵ�ͼ��������������֡�\n" NOR;
     }
    else if ( me->query_jibie( "huoyan-dao" )>149)
    {       point=0;
            msg += WHT"ֻ����ʯ���ϵ�һ����ʽ���Ѿ����������ˡ�\n" NOR;
     }     
    else {
    point = me->query_xiuwei("blade")/1500;
    msg += HIM"ֻ��ʯ�����������������Ĺ�����ʽ�������һ��Ҳ��ͬС�ɡ�\n" NOR; 
        if( !me->query_jibie("huoyan-dao") )
            msg += HIM"������ѧ���˾����ĵĵ�����\n"NOR;
     
        msg += HIG "��ġ����浶�������ˣ�\n" NOR;
        me->improve_jibie("huoyan-dao", 1);
        me->improve_xiuwei("blade",  point); 
        msg += HIW"��ġ� �� �� ������Ϊ������ߡ�"NOR;
        me->improve_xiuwei("zonggang", random(point) );        
        msg += HIW"�ڡ� �� ѧ ���ϵ�����Ҳ�����ˡ�\n"NOR;
    }
    
    tell_object( me, msg );
    me->receive_damage("gin", 100);
    me->enable_path();
}