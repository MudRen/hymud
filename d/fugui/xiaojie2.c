 inherit ROOM;
void create()
{
        set("short", "��ʯС��"); 
        set("long", @LONG
��������������С�򣬽ֵ�����խ��Щ�������е㶸б�����Է��ݵĹ���Ҳ��
ƽ�������ֺܾ���ֻ�������ҵĴ������ȼ�Ű����ĵƻ𡣶����Ǵ˵ض���һ��
�ľƵ꣬���ֺŵġ���Ԫ�ݡ�����������һ���ӻ��̡�
LONG);
        set("type","street");
        set("outdoors", "fugui");
        set("exits",([
                "east":__DIR__"kuiyuanguan",
                "west":__DIR__"zuohuopu",
                "south":__DIR__"xiaojie3",
                "north":__DIR__"xiaojie1",
        ]) );
        set("coor/x",-580);
        set("coor/y",110);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
