//ta.c.��
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"��������"NOR);
    set("long",@LONG
���øߵ���!���㲻���޵������ǳ����µĸ���������ȫ���Ĺ���ߵķ�����
Ҳ����ȫ���Ĺ�����Ϊ�Ժ���һ�����̡�ȫ������שľ�ṹ�������������Ϻ�ճ
���ճɵĲʴ���Ҥ���档ʵ�ĵ��������ֳ�ʮ�˲㣬ÿһ�����涼���������
ͼ����ÿһ��������¶������������ᣬ��һ���������������綼�ǡ����㡫��
�㡫���������������ֶ����ǡ���һ���ж����ϣ��������ĸ����ӣ��ƺ�����ת
��(zhuan)��
LONG);
   
    set("exits",([
        "north"   : __DIR__"tianjing1",
    ])); 
    set("dan",1);
    setup();
}

void init()
{
    add_action("do_zhuan","zhuan");
}

int do_zhuan(string arg)
{
    object me,ob,room;
    string str;
    int i,j;
    me = this_player();
    if ( !room = load_object("/d/xibei/xingqing/ta") )
          room = find_object("/d/xibei/xingqing/ta");
    if ( !arg )
    return notify_fail("��ϹתЩʲô��?....\n");
    if ( arg != "east" && arg != "south" && arg != "west"  && arg != "north" )
    return notify_fail("��ϹתЩʲô��?....\n"); 
    if ( !objectp(ob = present("yang pi", me)) )
    return notify_fail("��ת��һ�����ӣ�Ī������....\n");
    i = ob->query("dan");
    i += 1;
    if ( arg == "east" ) j =0;
    if ( arg == "south") j =1;
    if ( arg == "west" ) j =2;
    if ( arg == "north") j =3;
    str = "dan_bi_"+(string)i;
    if ( ob->query(str) != j ) i =0;
    if ( i < 9 )
    {
       ob->set("dan",i);
       write("��������ѽѽ��ת��һ��.....\n");
       return 1;
    }
    ob->set("dan",0);
    write("�����ƿ���¶��һ������..........\n");
    if ( room -> query("dan")== 0 )
    {
       write("����տյ���,ʲôҲû��......\n");
       return 1;
    }
    write("�Ӷ��ﻬ��һ����˿����ŵĶ��������ڵ��ϣ�¶��һ������\n");
    new("/d/xibei/xingqing/npc/obj/bi")->move(room);
    room -> set("dan",0);     
    return 1;
}

