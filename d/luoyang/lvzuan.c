// Room: /d/luoyang/lvzuan.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "������");
	set("long",  @LONG
�������ֽ����������������£��������֣�����Ϊ������ˮ����
��ԫ�̻���������С�����磬�������������������ɾ��������ֳ�Ϊ
���֣�����������Ъ��֮�������Ϊ���̳����������е�����ȫ���ɣ�
�������ȫ���ɡ����桱֮һ������������ʩ������δ�䣬�������
ģ��С�����Գơ������֡�����ơ����������� 
LONG);
	set("exits",  ([  
		"southwest" : "/d/luoyang/mangshan",
	]));
        set("objects", ([
                "/d/jinyong/book8/luoyang/npc/fei" : 1,
                "/d/jinyong/book8/luoyang/npc/yao" : 1,
                "/d/jinyong/book8/luoyang/npc/feng-buping" : 1,
                "/d/jinyong/book8/luoyang/npc/dizi" : 3,
        ]));
        
       	set("outdoors", "luoyang");

	setup();
	replace_program(ROOM);
}

void init()
{
	object who = this_player();
	if (who && interactive(who)) 
		call_out ("fengsay", 1, who);  
}

void fengsay(object who)
{
	object feng = present("feng buping", environment(who));
	if(feng)
	{
		message_vision("�ⲻƽ�޺޵�˵���������ɽ��֧�֣��ض�Ҫɱ������Ⱥ���������֮λ����\n");
		message_vision("Ȼ��ȥȪ��ɱ��ħ��ʹ�������죬�һ�ɽ�ɴӴ��������£���������\n");
	}
}