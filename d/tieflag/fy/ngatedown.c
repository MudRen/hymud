 inherit ROOM;
void create()
{
        set("short", "�����Ǻ�");
        set("long", @LONG
ǳǳ�Ļ��Ǻ�ˮ����Ϊ�ս�������Ѿ�ֻʣ��ʪ��������ˡ��ӵ�������
�������ڣ��ںڲ�����ͷ������������м����ƺ���һ��ָ���µĴ��֣���
�������������ϧ�ʲ����⣬�������ǿͣ�С����㡹��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
"up" : "/d/tieflag/fy/ngate",
  "enter" : __DIR__"nnewbie1",
  
]));
        set("objects", ([
  //      __DIR__"npc/wind_solider" : 2,
    //    __DIR__"npc/cloud_solider": 2, 
                        ]) );
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",60);
        set("coor/z",-10);
        
        setup();
}

int valid_leave(object me, string dir)
{
        if(dir == "enter"){
    if( me->query("mark/newbie")< 300 && (int) me->query("combat_exp")<300000)
                {me->add("mark/newbie",1);
                return 1;               }
        else  return notify_fail("һ�������������˳�����һ�����Ƶ���������������������������ʳ��\n");
        }
        return 1;
}  
