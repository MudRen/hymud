// Room: /d/welcome/newbie3
inherit ROOM;

void create ()
{
  set ("short", "��ػᰵ����");
  set ("long", @LONG
�ص���һƬ��ڣ������ķ���������˷���������ʲôҲ��������
ֻ���ڵص���Ϲ����ײ�������ƺ�����ԼԼ����˵������ֻһ�����û
���ˡ���ʹ����ҡ��ҡͷ���ܻ����⵽���ǲ��ǻþ����������Ѿ���·
�ˡ�
������24��·�ֱ�ͨ��
yz ���� bj ���� xy ���� dl ���� lz ���� xz ����
qz Ȫ�� wg ��� jp �ձ� cd �ɶ� km ���� xj �½�
dx ���� ca ���� jz ���� yj ʢ�� sz ���� fz ����
cz ���� yx ���� yy ���� yp ��ƽ hz ���� bl ����
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "yz" : "/d/city/guangchang",
  "bj" : "/d/beijing/kedian",
  "xy" : "/d/xiangyang/kedian",
  "dl" : "/d/dali/kedian",
  "qz" : "/d/quanzhouchen/kedian",
  "wg" : "/d/wuguan/guanmen",
  "jp" : "/d/japan/dongmen",
  "cd" : "/d/chengdu/kedian",
  "lz" : "/d/lanzhou/kedian",
  "km" : "/d/kunming/kedian",		
  "xz" : "/d/xizang/octostreet",		
  "xj" : "/d/xinjiang/nanmen",	
"dx" : "/d/dingxiang/beidajie1",	
"ca" : "/d/changan/ca",	
"jz" : "/d/jingzhou/guangchang",	
"yj" : "/d/yanjing/street",	
"sz" : "/d/suzhou/canlangting",	
"fz" : "/d/fuzhou/majiu",	  
"cz" : "/d/cangzhou/beimen",	
"yx" : "/d/yixing/yixing",	
"yy" : "/d/yueyang/guangchang",	
"yp" : "/d/yanping/majiu",	
"hz" : "/d/hangzhou/kedian",	
"bl" : "/d/baling/dongdajie1",	  
  "north" : "/d/beijing/andao10",	
]));


  setup();
}
int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	

		if ( me->query("family/family_name") != "������" && dir !="north")
		return notify_fail("ֻ����ػ���˶���ʹ������İ�����\n");
	


	return ::valid_leave(me, dir);
}
