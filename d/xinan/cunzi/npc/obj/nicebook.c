//
//nicebook.c

inherit ITEM;

void create()
{
    set_name("����Ư��ͼ", ({ "yangliu tu", "shu", "book" }));
    set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","��");
        set("long","���ƺ����Ʋ��������������ƺ�������ʲô��ѧ�����С�\n");
        set("value", -1);
        set("material", "paper");
        set("skill", ([
                "name"             : "chusuifeng",
                "xiuwei_required"  : 300,
                "literate_required": 30,
                "gin_cost"         : 10+random(10),
                "max_jibie"        : 100,
                "bonus_jilei"      : 0,
                "bonus_xiuwei"     : 6,
                "max_xiuwei"       : 800,
                "bonus_combat_exp" : 0,
                "max_combat_exp"   : 0,
                "bonus_social_exp" : 10,
                "max_social_exp"   : 100000,
                ]) );
        }
}

