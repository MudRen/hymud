inherit ROOM;

void create()
{
	set("short", "����̨");
	set("long", @LONG
��������̨�ɴ���ʯ������ÿ���ʯ����ü���ƽ����������Ϊ��
��������������ģ�������£��ƿ����ʣ����費������Ŀ��������ң
���ɸ����ţ��ƺ�����һ�ߣ��������������������ڣ����϶��ǵ�����
ɽ��
LONG );
	set("exits", ([
		"eastdown" : "/d/songshan/shandao8",
	"westup" : __DIR__"fengchantai2",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/bo": 1,
		CLASS_D("songshan")+"/sha": 1,
                __DIR__"master/master" : 1,

	]));
	set("outdoors", "songshan");
	set("coor/x", -30);
	set("coor/y", 850);
	set("coor/z", 90);
	setup();
	//replace_program(ROOM);
}



int valid_leave(object me, string dir)
{
        if(((int)me->query("jinyong/book8")!=9)&&(dir == "westup"))
        {
                return notify_fail("�������ھ���������ᣬ��ǹ���ۣ���Ҫ��ȥ�����ˡ�\n");
        }

        return ::valid_leave();
}
