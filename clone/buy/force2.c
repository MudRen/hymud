// shenliwan.c ��Ե��

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "˫�ڵ�" NOR, ({ "force wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ���߲ʵ�˫�ڵ�����˵���˿�������ѡ��˫�ڹ���\n");
                set("value", 10000);
		set("no_put",1);
		set("unit", "��");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;
int i;
        me = this_player();
        if (! id(arg))
{
tell_object(me, "��Ҫ��ʲô?\n");
                return notify_fail("��Ҫ��ʲô��\n");
}

i=0;




    if ( !me->query("zhuanshen")    )
{
tell_object(me, "��û��ת��!\n");
        return notify_fail("��û��ת��!\n");
}

    if ( me->query("tforceok")==2    )
{
tell_object(me, "�㲻��Ҫ����!\n");
        return notify_fail("�㲻��Ҫ����!\n");
}

        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);

        if (	me->query_skill("bahuang-gong",1)) i=i+1;
        if (	me->query_skill("xuantian-wuji",1)) i=i+1;
	if (	me->query_skill("beiming-shengong",1)) i=i+1;
	if (	me->query_skill("bibo-shengong",1)) i=i+1;
	if (	me->query_skill("hamagong",1)) i=i+1;
	if (	me->query_skill("huagong-dafa",1)) i=i+1;
	if (	me->query_skill("huntian-qigong",1)) i=i+1;
	if (	me->query_skill("jiuyang-shengong",1)) i=i+1;
	if (	me->query_skill("kuihua-xinfa",1)) i=i+1;
	if (	me->query_skill("kurong-changong",1)) i=i+1;
	if (	me->query_skill("linji-zhuang",1)) i=i+1;
	if (	me->query_skill("longxiang",1)) i=i+1;
 	if (	me->query_skill("shenlong-xinfa",1)) i=i+1;
	if (	me->query_skill("xiantian-qigong",1)) i=i+1;
	if (	me->query_skill("xiaowuxiang",1)) i=i+1;
	if (	me->query_skill("yijinjing",1)) i=i+1;
	if (	me->query_skill("yunv-xinfa",1)) i=i+1;
	if (	me->query_skill("yunlong-shengong",1)) i=i+1;
	if (	me->query_skill("shenyuan-gong",1)) i=i+1;
	if (	me->query_skill("huashan-neigong",1)) i=i+1;
        if (	me->query_skill("zixia-shengong",1)) i=i+1;
        if (	me->query_skill("shayi-xinfa",1)) i=i+1;
        if (	me->query_skill("biyun-xinfa",1)) i=i+1;
        if (	me->query_skill("bingxue-xinfa",1)) i=i+1;
        if (	me->query_skill("wudu-shengong",1)) i=i+1;
        if (	me->query_skill("taiji-shengong",1)) i=i+1;
        if (	me->query_skill("guiyuan-tunafa",1)) i=i+1;

	if (	me->query_skill("longxiang",1) && me->query_skill("xiaowuxiang",1)) i=i-1;
	if (	me->query_skill("beiming-shengong",1) && me->query_skill("bahuang-gong",1)) i=i-1;


        if (i>1)
        {
tell_object(me, "���ȷ��� �����϶��಻Ҫ���ڹ������ڹ���"+i+"�ţ�ֻ����һ�����ڹ���!\n");
                return notify_fail("���ȷ��� �����϶��಻Ҫ���ڹ���ֻ����һ�����ڹ���\n");
}
   

                message_vision("$Nգգ�ۡ�\n", me);
                tell_object(me, "��������"+i+"���ڹ���\n");



                tell_object(me, HIR "������ƺ��Լ������˱仯 ��\n" NOR);
                me->set("tforceok",2);

        destruct(this_object());
	return 1;
}
