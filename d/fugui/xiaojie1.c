 inherit ROOM;
void create()
{
        set("short", "��ʯС��"); 
        set("long", @LONG
��������������С�򣬽ֵ�����խ��Щ�������е㶸б�����Է��ݵĹ���Ҳ��
ƽ�������ֺܾ���ֻ�������ҵĴ����ﻹȼ�Ű����ĵƻ𡣱�����У�·Ҳ��խ��
�������������ջ���߸ߵش��ŵ�����С�ֶ���������ͨ�˼ҡ�
LONG);
        set("type","street");
        set("outdoors", "fugui");
        set("exits",([
                "east":__DIR__"home",
                "west":__DIR__"kezhan",
                "south":__DIR__"xiaojie2",
                "north":__DIR__"shandao9",
        ]) ); 
        set("coor/x",-580);
        set("coor/y",120);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
