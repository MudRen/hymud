// ����־ /d/city/chuzhou/dili_zhi.c
// by lala, 1997-12-13

inherit ITEM;

int do_read( string arg );

void create()
{
    set_name( "������־��", ({ "dili zhi", "zhi", "book", "shu" }));
    set_weight(300);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set( "unit", "��" );
        set( "long", "����һ����Ȥ�ġ�����־�����������ǱȽϾ��ˣ����ڻ���Ӱ���Ķ���\n" );
        set( "value", 2500 );
        set( "material", "paper" );
        set( "skill", ([
            "name"                      :   "literate",  
            "xiuwei_required"           :   0,
            "literate_required"         :   40,
            "gin_cost"                  :   25+random(10),
            "max_lingwu"                :   70,
            "bonus_jilei"               :   5,
            "bonus_social_exp"          :   5,
            "max_social_exp"            :   6200,
        ]) );
    }
}

  
