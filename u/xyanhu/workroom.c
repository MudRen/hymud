// Room: /d/wizard/wizard_room.c

inherit ROOM;

void create()
{
              set("short", "�����Ĺ�����");
	set("long", @LONG
�����Ǳ����Ĺ����䣬�Դ���arch����������װ��һ�£�
��Ȼֻ��һ�����䣬������ӣ����Ǵ�������������ܰ��
�����������������ҶԻ���ѧϰ�򵥱�̼��ɡ�
���˵�ʱ��ͷ������������ڹ���̨����Ϣһ�¡�


LONG );

	set("exits", ([ /* sizeof() == 1 */
                  "down" : "/d/city/guangchang",
            "wl" : "/d/wizard/wizard_room",
              "lj" : "/u/guaf/lujing",
	]));
                set("objects",([
      "/clone/gem/zhang" : 1,
          "/clone/gem/gem.c" : 3,
          "/d/pingan/npc/tang.c" : 1,
          "/d/pingan/npc/xiangling.c" : 1,
           "/quest/menpai/wudujiao/shi" : 1,
    ]));
//        set("no_fight", "0");
	set("no_clean_up", 0);
        set("valid_startroom", "1");
	setup();

        call_other("/u/guaf/guaf_b", "???");
	replace_program(ROOM);
}
