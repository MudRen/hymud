 // Room: yushijie2.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "����ʯ��"); 
        set("long", @LONG
������ͨ���޹�ɽׯ�İ���ʯ��,��Ȼ����ȥ��������Զ,��ʯ�����ѱ�������
����ǽ���,�����Եø����ׯ�ض��ྲ,����ɫ���ߣ��������������������Ĺ⣬
��ʯ���״ӻƽ��ĸ�ǽ�䴩��ȥ������ɽׯ��������ȫ���鱦�ƽ����ɵġ�����
ɽ������,��ɽ����,���õ������£�Զ����һƬ�Ի���ΰ��ׯԺ��������������
�еĹ���һ����
LONG); 
        set("exits",([
    "southdown":__DIR__"yushijie3",
    "northup":__DIR__"yushijie1",
        ]) );
        //}}
        set("outdoors", "taishanfy");
        set("coor/x",310);
        set("coor/y",2410);
        set("coor/z",140); 
        setup();
        replace_program(ROOM);
}     
