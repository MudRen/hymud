 inherit ROOM;
void create()
{
        set("short", "���Ź���ɳĮ");
        set("long", @LONG
���ŵ��ϵĻ�ɳ����ؼ�·��ѳ���һƬ���Եİ���ɫ��Ҳ��֪�����ﴫ����
һ������ĸ�������һ�����Źأ������᲻�ɡ�������һ��绯�˵�ʯ������Լ��
�Կ��������Źء�������׭���֡�
LONG
        ); 
        set("exits", ([ 
                "southeast" : __DIR__"mirage",
                "northwest" : __DIR__"kongquehe",
                "southwest" : "/d/qilian/yumenguan",
                "west" : "/d/eren/yangguan",	
        ]));
        set("outdoors", "loulan");
        set("coor/x",-950);
        set("coor/y",110);
        set("coor/z",0);
        setup();
}  
