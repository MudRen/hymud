#include <ansi.h>
inherit ITEM;


void create()
{
	set_name(HIR"Ѫ��"NOR, ({ "xue yi", "cloth" }));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("long","����ɱ�˵�����ͼ�ס�
����Ϳ���������飬���Ǹ��˵�Ѫ����\n");
		set("value",0);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("material","paper");
		set("cant_sell","����ɻ�Ŀ����㣺�����в�ѽ���������߰�����Ʋ�Ҳ��������\n");
		set("skill",([
			"name"			: "blade",
			"jing_cost"		: 0,
			"xiuwei_required"	: 5300,
			"literate_required"	: 150,
			"bonus_jilei"		: 0,
                        "max_jibie"		: 300,
			"bonus_xiuwei"		: 0,
			"max_xiuwei"       	: 5300,
		]) );
	}
}

varargs int move(mixed dest, int silent)
{
    object ob=this_object();

    if( ob->query("cant_move") )
    {
        destruct(ob);
        return 1;
    }
    return ::move(dest, silent);
}