// qiaobi.c
// by dicky

inherit ROOM;

void create()
{
        set("short","峭壁");
        set("long", @LONG
你走走停停，发现自己来到一段峭壁，抬头隐约可见山雾环绕的山崖，
山风拂面，鸟鸣声声，令人心旷神怡。路面上的砾石凹凸不平，一不小心
就可能要摔下深渊。一般人到了这里就不敢再向前了。
LONG                           
        );

        set("outdoors", "houjizhen");

        set("exits", ([
              "eastdown" : __DIR__"shanlu5",
              "westup" : __DIR__"shanya",
        ]));

	setup();
	replace_program(ROOM);
}

