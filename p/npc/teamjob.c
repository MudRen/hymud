int time_period(int timep,object me);
string  zuji(string str);
void zujinpc(object me,object obj);
int ckiller=4;
#include <ansi.h>
#include "/quest/menpai/givegift.c"
mapping *wheres=({
          
      (["chinese":                "������",
       "weizhi" :              "/d/dali/northgate",]),  
      (["chinese":                "��������",
       "weizhi" :              "/d/city/jiaowai5",]),  
     (["chinese":                "���Ҳ���",
       "weizhi" :              "/d/emei/caopeng",]),
     (["chinese":                "��������",
       "weizhi" :              "/d/city/ximen",]),
     (["chinese":                "ѩɽ��·",
       "weizhi" :              "/d/xueshan/tulu2",]),
     (["chinese":                "������԰",
       "weizhi" :              "/d/suzhou/liuyuan",]),
     (["chinese":                "���ݺ�ɽ��",
       "weizhi" :              "/d/suzhou/hanshansi",]),
     (["chinese":                "���ݷ�����",
       "weizhi" :              "/d/hangzhou/feilaifeng",]),
     (["chinese":                "���ݾ�����",
       "weizhi" :              "/d/hangzhou/jingcisi",]),
     (["chinese":                "���ݴ�΢ͤ",
       "weizhi" :              "/d/hangzhou/cuiweiting",]),
     (["chinese":                "���ݾ۾�԰",
       "weizhi" :              "/d/hangzhou/jujingyuan",]),
     (["chinese":                "�置��Ϫ��",
       "weizhi" :              "/d/dali/yixibu",]),  
      (["chinese":                "��������㳡",
       "weizhi" :              "/d/city/guangchang",]),  
      (["chinese":                "�����غ����",
       "weizhi" :              "/d/hangzhou/dadao1",]), 
      (["chinese":                "���ݶ���",
       "weizhi" :              "/d/hangzhou/duanqiao",]), 
      (["chinese":                "����������",
       "weizhi" :              "/d/hangzhou/lingyinsi",]), 
      (["chinese":                "���޺�����",
       "weizhi" :              "/d/xingxiu/beijiang",]), 
      (["chinese":                "�䵱������",
       "weizhi" :              "/d/wudang/santiangate",]), 
      (["chinese":                "����ʮ����",
       "weizhi" :              "/d/emei/shierpan3",]), 
      (["chinese":                "����ǧ����",
       "weizhi" :              "/d/emei/qianfoan",]), 
      (["chinese":                "���Ҿ�ʮ�ŵ���",
       "weizhi" :              "/d/emei/jsjdg1",]), 
      (["chinese":                "���̺�������",
       "weizhi" :              "/d/mingjiao/htqmen",]), 
      (["chinese":                "�����һ������",
       "weizhi" :              "/d/mingjiao/lhqhoumen",]), 
      (["chinese":                "���ݶ���",
       "weizhi" :              "/d/fuzhou/dongmen",]), 
      (["chinese":                "���ݱ����",
       "weizhi" :              "/d/fuzhou/beidajie",]), 
      (["chinese":                "���޺�ɳĮ",
       "weizhi" :              "/d/xingxiu/shamo2",]),
      (["chinese":                "������ʯ��",
       "weizhi" :              "/d/shaolin/shijie4",]),
      (["chinese":                "����ʯ��",
       "weizhi" :              "/d/xiangyang/walle1",]),
      (["chinese":                "��ɽ�����",
       "weizhi" :              "/d/huashan/husun",]),
      (["chinese":                "��ɽ��Ů��",
       "weizhi" :              "/d/huashan/yunu",]),
      (["chinese":                "Ľ��С��",
       "weizhi" :              "/d/mr/xiaojing1-2",]),
      (["chinese":                "Ľ��������",
       "weizhi" :              "/d/mr/liulin",]),
      (["chinese":                "�����ͽ�",
       "weizhi" :              "/d/dali/dahejiewest",]),
      (["chinese":                "���ݳǱ���",
       "weizhi" :              "/d/suzhou/beimen",]),
      (["chinese":                "���ݳ������",
       "weizhi" :              "/d/suzhou/xuanmiao",]),
      (["chinese":                "������ɽ�ŵ�",
       "weizhi" :              "/d/shaolin/smdian",]),
      (["chinese":                "����������",
       "weizhi" :              "/d/shaolin/zoulang7",]),
      (["chinese":                "�䵱ɽ·",
       "weizhi" :              "/d/wudang/shanlu3",]),
      (["chinese":                "�����°����þŲ�",
       "weizhi" :              "/d/shaolin/banruo9",]),
      (["chinese":                "ѩɽɽ��",
       "weizhi" :              "/d/xueshan/shanjiao",]),
      (["chinese":                "���Ҿ��϶�",
       "weizhi" :              "/d/emei/jiulaodong",]),
       (["chinese":                "���ҹŵ���",
       "weizhi" :              "/d/emei/gudelin1",]),
       (["chinese":                "�������Ź�",
       "weizhi" :              "/d/city4/hanguguan",]),
       (["chinese":                "��������ɽ��",
       "weizhi" :              "/d/city4/zhongnan",]),
       (["chinese":                "��������",
       "weizhi" :              "/d/fuzhou/fzroad8",]),
       (["chinese":                "��ˮ�ϰ�",
       "weizhi" :              "/d/shaolin/hanshui1",]),
       (["chinese":                "��ɽ����ɽ����",
       "weizhi" :              "/d/huashan/jzroad5",]),
       (["chinese":                "��ɽ����",
       "weizhi" :              "/d/xingxiu/shanjiao",]),
       (["chinese":                "��ɽ����",
       "weizhi" :              "/d/huashan/path1",]),
       (["chinese":                "ƽ����",
       "weizhi" :              "/d/heimuya/pingdingzhou",]),
       (["chinese":                "��ľ����ʯ��",
       "weizhi" :              "/d/heimuya/road1",]),      
       (["chinese":                "��ɽ���ϴ��",
       "weizhi":                "/d/village/sexit",]),
       (["chinese":                "���ӹŵ�",
       "weizhi":                "/d/fuzhou/fzroad7",]),
       (["chinese":                "̩ɽ��ʶ�",
       "weizhi":               "/d/taishan/yuhuang",]),
       (["chinese":                "��������ɽ",
       "weizhi":                "/d/xingxiu/xxroad3",]),
       (["chinese":                "������ɽɽ·",
       "weizhi":                "/d/xingxiu/tianroad1",]),
       (["chinese":                "���޼�����",
       "weizhi":                "/d/xingxiu/jiayuguan",]),
       (["chinese":                "�������������",
       "weizhi":                "/d/beijing/xidan1",]),
       (["chinese":                "����ͨ����",
       "weizhi":                "/d/city/tongsiqiao",]),
       (["chinese":                "�������������",
       "weizhi":                "/d/beijing/wangfu2",]),
       (["chinese":                "ȫ��̱�",
       "weizhi":                "/d/quanzhen/jiaobei",]),
       (["chinese":                "ȫ��������",
       "weizhi":                "/d/gumu/juyan",]),
       (["chinese":                "��������ͷ",
       "weizhi":                "/d/guanwai/laolongtou",]),
       (["chinese":                "���˳�",
       "weizhi":                "/d/jiaxing/jiaxing",]),
       (["chinese":                "��������",
       "weizhi":                "/d/city/ximen",]),
       (["chinese":                "������ϼ��",
       "weizhi":                "/d/fuzhou/fzroad1",]),
       (["chinese":                "̩ɽһ����",
       "weizhi":                "/d/taishan/yitian",]),
       (["chinese":                "����С����",
       "weizhi":                "/d/guanwai/tuwu",]),
       (["chinese":                "�����¹س�",
       "weizhi":                "/d/dali/xiaguan",]),
       (["chinese":                "����������ʯ��",
        "weizhi":                "/d/dali/shilin1",]),
        (["chinese":                "������ˮ�ٲ�",
        "weizhi":                "/d/dali/dadieshui",]),
        (["chinese":                "������٤��",
        "weizhi":                "/d/dali/luojiadian",]),
        (["chinese":                "����������",
        "weizhi":                "/d/dali/yangzong",]),
        (["chinese":                "����̫����",
        "weizhi":                "/d/songshan/taishique",]),
        (["chinese":                "����ʯ��",
        "weizhi":                "/d/shaolin/shijie7",]),
        (["chinese":                "��ɽ����Ͽ",
        "weizhi":                "/d/songshan/tieliang",]),
        (["chinese":                "��ɽ������Ժɽ��",
        "weizhi":                "/d/songshan/junjigate",]),
        (["chinese":                "��Ĺ���ԭ",
        "weizhi":                "/d/gumu/shenheyuan",]),
        (["chinese":                "����ɽ��У��",
        "weizhi":                "/d/gumu/daxiaochang",]),
        (["chinese":                "��ɽ������",
        "weizhi":                "/d/huashan/jinsuo",]),
        (["chinese":                "��ɽƽ��ʯ",
        "weizhi":                "/d/huashan/pingxinshi",]),
        (["chinese":                "��ɽǧ�ߴ�",
        "weizhi":                "/d/huashan/qianchi",]),
        (["chinese":                "��ɽɽ���ٲ�",
        "weizhi":                "/d/huashan/shanhongpb",]),
        (["chinese":                "����������",
        "weizhi":                "/d/emei/qingyinge",]),
        (["chinese":                "���Ҿ��϶���",
        "weizhi":                "/d/emei/jldongkou",]),
        (["chinese":                "����ǧ����",
        "weizhi":                "/d/emei/qianfoan",]),
        (["chinese":                "����ɽ�յ�",
        "weizhi":                "/d/gumu/kongdi",]),
        (["chinese":                "����ɽ����",
        "weizhi":                "/d/gumu/zhufeng",]),
        (["chinese":                "����������",
        "weizhi":                "/d/mingjiao/shanlu3",]),
         (["chinese":                "�����һ������",
        "weizhi":                "/d/mingjiao/lhqmen",]),
        (["chinese":                "ѩɽ��ɽ��",
        "weizhi":                "/d/xueshan/shanmen",]),
        (["chinese":                "���̺�ˮ�����",
        "weizhi":                "/d/mingjiao/hsqmen",]),
        (["chinese":                "�䵱��ʯ���",
        "weizhi":                "/d/wudang/wdroad1",]),
        (["chinese":                "���������",
        "weizhi":                "/d/city4/road1",]),
        (["chinese":                "̩ɽ�����",
        "weizhi":                "/d/taishan/yidao",]),
        (["chinese":                "ȫ��ٵ�",
        "weizhi":                "/d/quanzhen/guandao2",]),
        (["chinese":                "�书�򶫽�",
        "weizhi":                "/d/quanzhen/dongjie",]),
        (["chinese":                "�书�򸻼Ҵ���",
        "weizhi":                "/d/quanzhen/fu-damen",]),
        (["chinese":                "ȫ��ɽ·",
        "weizhi":                "/d/quanzhen/shanlu1",]),
        (["chinese":                "ȫ��С��ׯ",
        "weizhi":                "/d/quanzhen/xiaocun",]),
        (["chinese":                "���޺�",
        "weizhi":                "/d/xingxiu/xxh2",]),
        (["chinese":                "������ɽ����",
        "weizhi":                "/d/xingxiu/shanjiao",]),
        (["chinese":                "����˿��֮·",
        "weizhi":                "/d/xingxiu/silk2",]),
        (["chinese":                "����������",
        "weizhi":                "/d/city4/westgate",]),
        (["chinese":                "�����Ƕ���",
        "weizhi":                "/d/city4/eastgate",]),
        (["chinese":                "��ɽ������",
        "weizhi":                "/d/huashan/shangtianti",]),
        (["chinese":                "��ң����",
        "weizhi":                "/d/xiaoyao/shulin3",]),
        (["chinese":                "��������",
         "weizhi":                "/d/city/nanmen",
        ]),
       (["chinese":     "�����ԯ��",
       "weizhi" :   "/d/xibei/kongdong/xuanyuan_gong",]),       
       (["chinese":     "���������´���",
       "weizhi" :   "/d/tianlongsi/damen",]),       
       (["chinese":     "������������",
       "weizhi" :   "/d/tangmen/zhulin",]),       
       (["chinese":     "̫ԭ�������",
       "weizhi" :   "/d/taiyuan/xidajie1",]),       
       (["chinese":     "�Ϸʳ������",
       "weizhi" :   "/d/hefei/xidajie3",]),       
       (["chinese":     "�Ž��Ƕ����",
       "weizhi" :   "/d/jiujiang/dongdajie2",]),       
       (["chinese":     "��Ҷ�Ǳ����",
       "weizhi" :   "/d/suiye/beidajie1",]),       
       (["chinese":     "����Ǳ����",
       "weizhi" :   "/d/dingxiang/beidajie1",]),       
       (["chinese":     "�½�����������",
       "weizhi" :   "/d/xinjiang/nanmen",]),       
       (["chinese":     "���ݳ������",
       "weizhi" :   "/d/xuzhou/xidajie",]),       
       (["chinese":     "������ʮ�ֽ�ͷ",
       "weizhi" :   "/d/guizhou/center",]),       
       (["chinese":     "�ϲ��ǹ㳡",
       "weizhi" :   "/d/nanchang/center",]),       
       (["chinese":     "��ɳ�ǹ㳡",
       "weizhi" :   "/d/changsha/guangchang",]),       
       (["chinese":     "��Զ�ǹٸ���վ",
       "weizhi" :   "/d/ny/postoffice",]),       
       (["chinese":     "����ʢ��ʮ��·��",
       "weizhi" :   "/d/fengtian/cross",]),       
       (["chinese":     "��Ż���������",
       "weizhi" :   "/d/feitian/damen",]),       
       (["chinese":     "������Ҵ���",
       "weizhi" :   "/d/zhongzhou/miaojia_men",]),       
       (["chinese":     "��ǽ�����",
       "weizhi" :   "/d/qingcheng/jianfugong",]),       
       (["chinese":     "��ɽ̫����",
       "weizhi" :   "/d/songshan/taishique",]),       
       (["chinese":     "̩ɽ��ڷ�",
       "weizhi" :   "/d/taishan/daizong",]),       
       (["chinese":     "��ɽɯ��ƺ",
       "weizhi" :   "/d/huashan/shaluo",]),       
       (["chinese":     "��ɽ������",
       "weizhi" :   "/d/henshan/lingxingmen",]),       
       (["chinese":     "��ɽ����Ͽ",
       "weizhi" :   "/d/hengshan/jinlongxia",]),       
       (["chinese":     "ȫ����ɽ��",
       "weizhi" :   "/d/quanzhen/shanjiao",]),       
       (["chinese":     "����ɽ�׺�",
       "weizhi" :   "/d/guanwai/baihe",]),       
       (["chinese":     "������ɽ��",
       "weizhi" :   "/d/mingjiao/shanmen",]),       
       (["chinese":     "ѩɽ��ɽ��",
       "weizhi" :   "/d/xueshan/shanmen",]),       
       (["chinese":     "������ʯ��",
       "weizhi" :   "/d/lingxiao/shiya",]),       
       (["chinese":     "��������ɽɽ·",
       "weizhi" :   "/d/xingxiu/tianroad2",]),       
       (["chinese":     "Ľ��������ͷ",
       "weizhi" :   "/d/mr/matou",]),       
       (["chinese":     "���������ʯ��",
       "weizhi" :   "/d/heimuya/road1",]),       
       (["chinese":     "����ɽ����ɽׯ",
       "weizhi" :   "/d/yandang/luoyan2",]),       
       (["chinese":     "���Ʒ�ɽ����",
       "weizhi" :   "/d/tiezhang/shanjiao",]),       
       (["chinese":     "������ɽ��",
       "weizhi" :   "/d/kunlun/shanmen",]),       
       (["chinese":     "��ü������",
       "weizhi" :   "/d/emei/bgs",]),       
       (["chinese":     "�䵱�⽣��",
       "weizhi" :   "/d/wudang/jiejianyan",]),       
       (["chinese":     "������ӭ��ͤ",
       "weizhi" :   "/d/nanshaolin/ting",]),       
       (["chinese":     "������ɽ��",
       "weizhi" :   "/d/shaolin/shanmen",]),       
       (["chinese":     "��翷�ɽ��",
       "weizhi" :   "/d/lingjiu/shanjiao",]),       
       (["chinese":     "����ɽׯ����",
       "weizhi" :   "/d/baituo/dating",]),       
       (["chinese":     "�һ�������",
       "weizhi" :   "/d/taohua/dating",]),       
       (["chinese":     "�����̴���",
       "weizhi" :   "/d/shenlong/dating",]),       
       (["chinese":     "�컨�����",
       "weizhi" :   "/d/huizhu/damen",]),       
       (["chinese":     "������������",
       "weizhi" :   "/d/dali/wangfugate",]),       
       (["chinese":     "ؤ������",
       "weizhi" :   "/d/city/pomiao",]),       
       (["chinese":     "�������չ�¥",
       "weizhi" :   "/d/kunming/jinrilou",]),     
       (["chinese":     "�����찲��",
       "weizhi" :   "/d/beijing/tian_anm",]),     
       (["chinese":     "���ݲ���ͤ",
       "weizhi" :   "/d/suzhou/canlangting",]),     
       (["chinese":     "�����㳡",
       "weizhi" :   "/d/xiangyang/guangchang",]),     
       (["chinese":     "�����Ǵ��",
       "weizhi" :   "/d/changan/ca",]),     
       (["chinese":     "�ɶ��츮�㳡",
       "weizhi" :   "/d/chengdu/guangchang",]),     
       (["chinese":     "���ݹ㳡",
       "weizhi" :   "/d/lanzhou/guangchang",]),     
       (["chinese":     "��������",
       "weizhi" :   "/d/jingzhou/guangchang",]),     
       (["chinese":     "���ݳ�����",
       "weizhi" :   "/d/lingzhou/center",]),     
       (["chinese":     "���ݱ���",
       "weizhi" :   "/d/cangzhou/beimen",]),     
       (["chinese":     "����",
       "weizhi" :   "/d/yixing/yixing",]),     
       (["chinese":     "����������",
       "weizhi" :   "/d/tanggu/beimen",]),     
       (["chinese":     "�����㳡",
       "weizhi" :   "/d/yueyang/guangchang",]),     
       (["chinese":     "���걱����",
       "weizhi" :   "/d/jiangling/beimen",]),     
       (["chinese":     "���س���",
       "weizhi" :   "/d/xizang/citygate",]),
       (["chinese":     "���Ϻ�����ͷ",
       "weizhi" :   "/d/annan/matou",]),
       (["chinese":     "�����ۿ�",
       "weizhi" :   "/d/gaoli/gangkou",]),                  
           });
string *family_fame = ({
        "������",
        "�䵱��",
        "ؤ��",
        "ȫ���",
        "��ɽ��",
        "����μ�",
        "����Ľ��",
        "ѩɽ��",
        "���չ�",
        "������",
        "�һ���",
        "������",
        "��Ĺ��",
        "������",
        "��ң��",
        "����ɽ��",
        "�������",
        "����������", 	
        "������",
        "��������",
        "����",
        "������",
        "�嶾��",
        "���ư�",
        "����",
        "������",
        "�컨��",
        "��ɽ��",
        "̩ɽ��",
        "�����",
        "��ɽ��",
        "��ɽ��",
        "÷ׯ",
        "�������",
"������",
"������",
"���͵�",
"�����",
"�㵴��",	
});

string *typew=({
"sword",
"blade",
"hammer",
"whip",
"club",
"staff",
"throwing",
"dagger",
"axe",
});
string *typea=({
"hands",
"cloth",
"armor",
"boots",
"head",
"neck",
"surcoat",
"shield",
"waist",
"wrists",
});


mapping *lquest1 = ({
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�佫", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�ٱ�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 		
([ "quest_name": "��С��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "���ϰ�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "Ǯ�ۿ�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "���", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��å", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��åͷ", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "ƽһָ", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "ҩ�̻��","exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "С����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "̷�Ѽ�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��ҩ��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "ʷ��ɽ", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�η�����","exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "���е�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�Ҷ�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�ܼ�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��Ա��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��ݺݺ", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�⹭Ӱ", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "Ľ��Ѳ��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�һ��峤","exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�һ�ͯ", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�к�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "ʷ��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�տն�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "ΤС��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "���", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "С���", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "���͹�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��ͷ��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����ɩ", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "Τ����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�깫", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "éʮ��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "ŷ����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��Ա��", 	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", 		"exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����Ȼ", 	 	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʯ", 	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���¶�",		"exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", 	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�Ų���", 	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "ŷ��Ѳ��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����Ѳ��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����Ѳ��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	

([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "Ү����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ͨ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ذ���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���׳����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "С��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ο�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�η�����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���ƹ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���峬", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "С��å", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��Ʀ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ƹ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�͵���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��ͷ��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��һ��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "Ǯ����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "���Ĵ�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����˥", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "֣����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	

([ "quest_name": "���Ҿ�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��ʦү", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����ǿ", 	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	

([ "quest_name": "�ذ���", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "������", 	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�ܴ��", 	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "���ϰ�", 	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	

([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "���Գ�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	

([ "quest_name": "�����ƹ�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "���²���", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	

([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��֮��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	

([ "quest_name": "��̩��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "����ľ��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ɽ" ]), 	

([ "quest_name": "��Ա��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"�书��" ]), 	

([ "quest_name": "��ݼ", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	

});

mapping *lquest2 = ({
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ذ���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���׳����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "С��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ο�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�η�����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���ƹ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���峬", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "С��å", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��Ʀ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ƹ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�͵���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��ͷ��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "̫��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "Ǯ�ϱ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���Ʋֹ�ʦ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���촨", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�Ϻ���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���ϰ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ϴ���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "��Զɽ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "�׹���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����ɽ��" ]), 	

([ "quest_name": "ɣ����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ľ��" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ľ��" ]), 	
	
([ "quest_name": "�����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "ɳͨ��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "��ͨ��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "Ǯ�ཡ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "��ǧ��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	

([ "quest_name": "ѦĽ��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ң" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ң" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ң" ]), 	
([ "quest_name": "���Ǻ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ң" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ң" ]), 	

([ "quest_name": "½��Ӣ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����ׯ" ]), 	

([ "quest_name": "��ǧ��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"���ư�" ]), 	

([ "quest_name": "�仨", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�书��" ]), 	
([ "quest_name": "�ر�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�书��" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�书��" ]), 	

([ "quest_name": "�ֺ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ɽ" ]), 	

([ "quest_name": "���ɵ���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"̩ɽ" ]), 	
([ "quest_name": "��ص���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"̩ɽ" ]), 	

([ "quest_name": "���ҵ���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"̩ɽ" ]), 	

([ "quest_name": "С��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "��ͨ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "��Ī��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "����ʦ̫", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ɽ" ]), 	

([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ɽ��" ]), 	


(["quest_name": "���Ҿ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "��ʦү", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����ǿ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	

(["quest_name": "�ذ���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	

(["quest_name": "��ҩʦ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��Ҷ" ]), 	
(["quest_name": "���ϰ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��Ҷ" ]), 	
(["quest_name": "���ƹ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��Ҷ" ]), 	
(["quest_name": "���ݷ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��Ҷ" ]), 	
	
(["quest_name": "Уξ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "�㷷��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "Ī����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	

(["quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ͬ" ]), 	
(["quest_name": "��������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ͬ" ]), 	
(["quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ͬ" ]), 	
(["quest_name": "��һ��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ͬ" ]), 	
(["quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ͬ" ]), 	
(["quest_name": "�Ƹ���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ͬ" ]), 	

(["quest_name": "л��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�㵴" ]), 	
(["quest_name": "��������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�㵴" ]), 	
(["quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�㵴" ]), 	
(["quest_name": "Գ����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�㵴" ]), 	

(["quest_name": "���ϰ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"̫ԭ" ]), 	
(["quest_name": "�����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"̫ԭ" ]), 	
(["quest_name": "��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"̫ԭ" ]), 	

(["quest_name": "�ϳ���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
});

mapping *lquest3 = ({
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
	
([ "quest_name": "ʷ��ͷ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�°���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��ʲ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ͷ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "³����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	

([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "Ү����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ͨ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��ܽ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "ľ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "ƫ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�α�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ϰ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���˿�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ͨ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "��̩��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�Ϻ���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "����ľ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	

([ "quest_name": "��Ա��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�书��" ]), 	

([ "quest_name": "��ݼ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��Ϊ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ﲮ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�販ʿ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "���ı�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�ƺӾ���" ]), 	
	
([ "quest_name": "�ƻ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�ɶ�" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�ɶ�" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�ɶ�" ]), 	
([ "quest_name": "���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�ɶ�" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�ɶ�" ]), 	
([ "quest_name": "�����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�ɶ�" ]), 	
([ "quest_name": "�˷��Ϸ���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�ɶ�" ]), 	
	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
([ "quest_name": "���ٴ�ʦ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	

([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����̩", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������ʿ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "ʿ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��ͷ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�̴�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����˾", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��Ů", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�κ�ҩ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "Ѧ�ϰ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "ʯ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������ʿ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��˼��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������ʿ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "̫��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��Ů", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��ũ�����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "��һ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����ʹ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�ų���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�ſ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�ϳ���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	

([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"Ȫ��" ]), 	
([ "quest_name": "��Ѷ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"Ȫ��" ]), 	
	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "ɳ�콭", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	

([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"���ɽ" ]), 	
([ "quest_name": "���˴�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"���ɽ" ]), 	
	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"Ľ��ɽׯ" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"Ľ��ɽׯ" ]), 	

(["quest_name": "�粨��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "����ͬ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "�˰ٴ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	

(["quest_name": "�߾��ٱ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
(["quest_name": "�߾��佫", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	 	
	
(["quest_name": "���ɩ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"ʢ��" ]), 	
(["quest_name": "���ĳ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"ʢ��" ]), 	
(["quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"ʢ��" ]), 	
(["quest_name": "�����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"ʢ��" ]), 	
(["quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"ʢ��" ]), 	
	
(["quest_name": "���Ҿ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
(["quest_name": "��ʦү", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����ǿ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
	
(["quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "Ԫ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "�����ʦ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "��۴�ʦ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "Ԫ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "Ԫ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "Ԫ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "����ʦ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
	
(["quest_name": "��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɳ" ]), 	
(["quest_name": "���ϰ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɳ" ]), 	
(["quest_name": "�δ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɳ" ]), 	
(["quest_name": "������Ů", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɳ" ]), 	
	
(["quest_name": "��С��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"���˹�" ]), 	
(["quest_name": "��ҩʦ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"���˹�" ]), 	
(["quest_name": "��Ƽ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"���˹�" ]), 	
(["quest_name": "��С·", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"���˹�" ]), 	
});

mapping *lquest4 = ({
([ "quest_name": "���״�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���׶���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�����Ļ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ֻ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ն���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��һ��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
	
([ "quest_name": "��ë��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"̨��" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"̨��" ]), 	
	
([ "quest_name": "Ī��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
	
([ "quest_name": "����ܽ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����Сʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����Сʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ϼ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
	
([ "quest_name": "����Ϫ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�䵱" ]), 	
([ "quest_name": "����ͤ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�䵱" ]), 	
([ "quest_name": "��Զ��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�䵱" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�䵱" ]), 	
([ "quest_name": "�������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�䵱" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�䵱" ]), 	
([ "quest_name": "�������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�䵱" ]), 	
([ "quest_name": "Ī����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�䵱" ]), 	
	
([ "quest_name": "�����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ٹ�" ]), 	
([ "quest_name": "�ʱ���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ٹ�" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ٹ�" ]), 	
	
([ "quest_name": "½�˷�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����ׯ" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����ׯ" ]), 	
([ "quest_name": "��СӨ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����ׯ" ]), 	
([ "quest_name": "�����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����ׯ" ]), 	
([ "quest_name": "ȫ��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����ׯ" ]), 	
([ "quest_name": "�Ű���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����ׯ" ]), 	
([ "quest_name": "��ϣ��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����ׯ" ]), 	
([ "quest_name": "���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����ׯ" ]), 	
	
([ "quest_name": "��ҩʦ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�һ���" ]), 	
	
([ "quest_name": "��׺�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���ɽ" ]), 	
([ "quest_name": "����Ӣ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���ɽ" ]), 	
	
([ "quest_name": "���޼�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��Ұ��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ذ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��Ȼ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ţ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��ԫ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "ׯ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʹ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��ɽ��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��ʿ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "��־��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ȫ��" ]), 	
([ "quest_name": "��־ƽ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ȫ��" ]), 	
([ "quest_name": "С��Ů", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��Ĺ" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��Ĺ" ]), 	
([ "quest_name": "�ֳ�Ӣ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��Ĺ" ]), 	
([ "quest_name": "Ƥ����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ȫ��" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ȫ��" ]), 	
([ "quest_name": "��־��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ȫ��" ]), 	
	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	
([ "quest_name": "Ѫ������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	
([ "quest_name": "ʤ��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	
([ "quest_name": "׿��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	
([ "quest_name": "���з�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	
([ "quest_name": "ˮ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	
([ "quest_name": "½����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	
	
([ "quest_name": "��ľ���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ѩɽ��" ]), 	
([ "quest_name": "��ľ���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ѩɽ��" ]), 	
([ "quest_name": "���»��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ѩɽ��" ]), 	
([ "quest_name": "���ײ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ѩɽ��" ]), 	
	
([ "quest_name": "�̴�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ѩɽ" ]), 	
	
([ "quest_name": "ɽ��ͷ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "ŷ����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "С��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���ͷ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ܼ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ϲ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������Ů", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���չ�" ]), 	
([ "quest_name": "÷��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���չ�" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���չ�" ]), 	
([ "quest_name": "�������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���չ�" ]), 	

([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���޺�" ]), 	
([ "quest_name": "�ɻ���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���޺�" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���޺�" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���޺�" ]), 	
([ "quest_name": "ժ����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���޺�" ]), 	
([ "quest_name": "ʨ����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���޺�" ]), 	

([ "quest_name": "��������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"̩ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"̩ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"̩ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"̩ɽ" ]), 	
([ "quest_name": "����ʤ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"̩ɽ" ]), 	
([ "quest_name": "���ŵ���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"̩ɽ" ]), 	

([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "ʩ����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����Ⱥ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����ɺ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�߸���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "��ƽ��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�͵�ŵ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	

([ "quest_name": "Ҷ����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�Ϻ�����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "ʯ����ʿ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ʹ���ʿ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "һƷ����ʿ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "�Ʋ���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ľ��" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ľ��" ]), 	
([ "quest_name": "�Ժ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ľ��" ]), 	
([ "quest_name": "�ų���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ľ��" ]), 	
([ "quest_name": "�ų˷�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ľ��" ]), 	
([ "quest_name": "�ֲ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ľ��" ]), 	
([ "quest_name": "������̽�ͽ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ľ��" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ľ��" ]), 	

([ "quest_name": "�����ʦ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��־", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ۿ�����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������ʦ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���ȴ�ʦ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���Ʊ���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������ʦ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���ޱ���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��Ϊ����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�巨����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "ɨ��ɮ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"������" ]), 	

([ "quest_name": "ʷ�Ǵ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "��Ӣ��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "���ƽ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "½��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�ѱ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�߿���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�˰���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
	
([ "quest_name": "֣��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�ؾ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�Ǻ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�Ƹ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 
		
(["quest_name": "���ϰ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����ү", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
(["quest_name": "�츻", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	

(["quest_name": "�Ʒ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����̫̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
(["quest_name": "������ʿ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
(["quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����ˮ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
(["quest_name": "������ʿ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	

(["quest_name": "��ά��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���ɽ" ]), 	
(["quest_name": "�����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���ɽ" ]), 	
(["quest_name": "�º���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���ɽ" ]), 	
(["quest_name": "ľ����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���ɽ" ]), 	
(["quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���ɽ" ]), 	
});
	
mapping *lquest = ({
([ "quest_name": "���״�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���׶���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�����Ļ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
	
([ "quest_name": "��ë��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"̨��" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"̨��" ]), 	

([ "quest_name": "Ī��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	

([ "quest_name": "����ܽ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����Сʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����Сʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ϼ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "����Ϫ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�䵱" ]), 	
([ "quest_name": "����ͤ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�䵱" ]), 	
([ "quest_name": "��Զ��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�䵱" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�䵱" ]), 	
([ "quest_name": "�������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�䵱" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�䵱" ]), 	
([ "quest_name": "�������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�䵱" ]), 	
([ "quest_name": "Ī����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�䵱" ]), 	

([ "quest_name": "�����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ٹ�" ]), 	
([ "quest_name": "�ʱ���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ٹ�" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ٹ�" ]), 	

([ "quest_name": "½�˷�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����ׯ" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����ׯ" ]), 	
([ "quest_name": "��СӨ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����ׯ" ]), 	
([ "quest_name": "�����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����ׯ" ]), 	
([ "quest_name": "ȫ��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����ׯ" ]), 	
([ "quest_name": "�Ű���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����ׯ" ]), 	
([ "quest_name": "��ϣ��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����ׯ" ]), 	
([ "quest_name": "���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����ׯ" ]), 	

([ "quest_name": "��ҩʦ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�һ���" ]), 	

([ "quest_name": "��׺�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���ɽ" ]), 	
([ "quest_name": "����Ӣ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"���ɽ" ]), 	
([ "quest_name": "���˴�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"���ɽ" ]), 	
([ "quest_name": "���˿�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"���ɽ" ]), 	
([ "quest_name": "����ͨ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"���ɽ" ]), 	

([ "quest_name": "���޼�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��Ұ��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ذ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��Ȼ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ţ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��ԫ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "ׯ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʹ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��ɽ��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��ʿ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "��־��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ȫ��" ]), 	
([ "quest_name": "��־ƽ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ȫ��" ]), 	
([ "quest_name": "С��Ů", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��Ĺ" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��Ĺ" ]), 	
([ "quest_name": "�ֳ�Ӣ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��Ĺ" ]), 	
([ "quest_name": "Ƥ����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ȫ��" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ȫ��" ]), 	
([ "quest_name": "��־��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ȫ��" ]), 	
	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	
([ "quest_name": "Ѫ������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	
([ "quest_name": "ʤ��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	
([ "quest_name": "׿��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	
([ "quest_name": "���з�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	
([ "quest_name": "ˮ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	
([ "quest_name": "½����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"Ѫ����" ]), 	

([ "quest_name": "��ľ���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ѩɽ��" ]), 	
([ "quest_name": "��ľ���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ѩɽ��" ]), 	
([ "quest_name": "���»��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ѩɽ��" ]), 	
([ "quest_name": "���ײ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ѩɽ��" ]), 	

([ "quest_name": "�̴�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ѩɽ" ]), 	

([ "quest_name": "ɽ��ͷ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "ŷ����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "С��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���ͷ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ܼ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ϲ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������Ů", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���չ�" ]), 	
([ "quest_name": "÷��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���չ�" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���չ�" ]), 	
([ "quest_name": "�������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���չ�" ]), 	

([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���޺�" ]), 	
([ "quest_name": "�ɻ���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���޺�" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���޺�" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���޺�" ]), 	
([ "quest_name": "ժ����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���޺�" ]), 	
([ "quest_name": "ʨ����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���޺�" ]), 	

([ "quest_name": "��������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"̩ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"̩ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"̩ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"̩ɽ" ]), 	
([ "quest_name": "����ʤ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"̩ɽ" ]), 	
([ "quest_name": "���ŵ���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"̩ɽ" ]), 	

([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "ʩ����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����Ⱥ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����ɺ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�߸���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "��ƽ��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�͵�ŵ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	

([ "quest_name": "Ҷ����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�Ϻ�����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "ʯ����ʿ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ʹ���ʿ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "һƷ����ʿ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "�Ʋ���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ľ��" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ľ��" ]), 	
([ "quest_name": "�Ժ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ľ��" ]), 	
([ "quest_name": "�ų���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ľ��" ]), 	
([ "quest_name": "�ų˷�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ľ��" ]), 	
([ "quest_name": "�ֲ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ľ��" ]), 	
([ "quest_name": "������̽�ͽ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ľ��" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ľ��" ]), 	

([ "quest_name": "ɨ��ɮ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"������" ]), 	

([ "quest_name": "�����ʦ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��־", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ۿ�����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������ʦ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���ȴ�ʦ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���Ʊ���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������ʦ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���ޱ���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��Ϊ����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�巨����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "ʷ�Ǵ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "��Ӣ��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "���ƽ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "½��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�ѱ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�߿���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�˰���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	

([ "quest_name": "֣��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�ؾ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����ʦ̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�Ǻ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�Ƹ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	

([ "quest_name": "���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ֻ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ն���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��һ��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	

(["quest_name": "���ϰ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����ү", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
(["quest_name": "�츻", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	

(["quest_name": "�Ʒ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����̫̫", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
(["quest_name": "������ʿ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
(["quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����ˮ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
(["quest_name": "������ʿ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	

(["quest_name": "��ά��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���ɽ" ]), 	
(["quest_name": "�����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���ɽ" ]), 	
(["quest_name": "�º���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���ɽ" ]), 	
(["quest_name": "ľ����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���ɽ" ]), 	
(["quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���ɽ" ]), 	

(["quest_name": "÷����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���" ]), 	
(["quest_name": "�ż���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"���" ]), 	

(["quest_name": "�Ի�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"����" ]), 	

(["quest_name": "��ɣ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�߲���" ]), 	
(["quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�߲���" ]), 	
(["quest_name": "�䳤", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�߲���" ]), 	

(["quest_name": "�Ű���", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�����" ]), 	
(["quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�����" ]), 	
(["quest_name": "�蹤", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"�����" ]), 	

(["quest_name": "κ�޼�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ѩͤ��" ]), 	
(["quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ѩͤ��" ]), 	
(["quest_name": "����һ��", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"ѩͤ��" ]), 	

(["quest_name": "��ķ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��һ��" ]), 	

(["quest_name": "��Ӣ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
(["quest_name": "����", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
(["quest_name": "��Ө", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
(["quest_name": "������", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
(["quest_name": "�չ�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
(["quest_name": "��ݦ", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	
(["quest_name": "�׻�", "exp_bonus":random(25)+30,"pot_bonus": random(12)+10 ,"quest_city":"��ɽ" ]), 	 

([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�佫", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�ٱ�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��С��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "���ϰ�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "Ǯ�ۿ�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "���", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��å", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��åͷ", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "ƽһָ", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "ҩ�̻��","exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "С����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "̷�Ѽ�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��ҩ��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "ʷ��ɽ", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�η�����","exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "���е�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�Ҷ�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�ܼ�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��Ա��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��ݺݺ", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�⹭Ӱ", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "Ľ��Ѳ��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�һ��峤","exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�һ�ͯ", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�к�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "ʷ��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�տն�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "ΤС��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "���", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "С���", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "���͹�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��ͷ��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����ɩ", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "Τ����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�깫", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "éʮ��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "ŷ����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��Ա��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����Ȼ", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ʯ", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���¶�","exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�Ų���", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 		
([ "quest_name": "ŷ��Ѳ��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����Ѳ��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����Ѳ��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "С��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��̩��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�Ϻ���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ذ���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���׳����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "С��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ο�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�η�����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���ƹ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���峬", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "С��å", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��Ʀ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ƹ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�͵���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��ͷ��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��Զɽ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "̫��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�׹���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����ɽ��" ]), 	
([ "quest_name": "Ǯ�ϱ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���Ʋֹ�ʦ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���촨", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�Ϻ���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���ϰ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ϴ���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��һ��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "Ǯ����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "���Ĵ�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����˥", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "֣����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
(["quest_name": "���Ҿ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
(["quest_name": "��ʦү", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����ǿ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "���Գ�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	

([ "quest_name": "�����ƹ�", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "���²���", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��������", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	

([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "�����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "��֮��", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	

([ "quest_name": "ɣ����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ľ��" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ľ��" ]), 	

([ "quest_name": "�����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "Ǯ�ཡ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "ɳͨ��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "��ͨ��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "��ǧ��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�ƺӾ���" ]), 	
([ "quest_name": "���ı�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�ƺӾ���" ]), 	

([ "quest_name": "ѦĽ��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ң" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ң" ]), 	
([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ң" ]), 	
([ "quest_name": "���Ǻ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ң" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ң" ]), 	

([ "quest_name": "½��Ӣ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����ׯ" ]), 	

([ "quest_name": "��ǧ��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"���ư�" ]), 	

([ "quest_name": "�仨", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�书��" ]), 	
([ "quest_name": "�ر�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�书��" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�书��" ]), 	
([ "quest_name": "��Ա��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�书��" ]), 	

([ "quest_name": "�ֺ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "ɳ�콭", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	

([ "quest_name": "���ɵ���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"̩ɽ" ]), 	
([ "quest_name": "��ص���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"̩ɽ" ]), 	
([ "quest_name": "���ҵ���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"̩ɽ" ]), 	

([ "quest_name": "��ͨ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "��Ī��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "����ʦ̫", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ɽ" ]), 	

([ "quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ɽ��" ]), 	

(["quest_name": "���Ҿ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "��ʦү", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����ǿ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
	
(["quest_name": "�ذ���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "��ҩʦ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "���ϰ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "���ƹ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "���ݷ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ܴ��", 	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "���ϰ�", 	"exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	

(["quest_name": "Уξ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "�㷷��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "Ī����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	

(["quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ͬ" ]), 	
(["quest_name": "��������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ͬ" ]), 	
(["quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ͬ" ]), 	
(["quest_name": "��һ��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ͬ" ]), 	
(["quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ͬ" ]), 	
(["quest_name": "�Ƹ���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ͬ" ]), 		
(["quest_name": "�����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ͬ" ]), 	
(["quest_name": "�ֱ�����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ͬ" ]), 	
(["quest_name": "�Ӽ���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ͬ" ]), 	
(["quest_name": "���ү", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ͬ" ]), 	

(["quest_name": "�׿�Զ", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"��ˮ" ]), 		 

(["quest_name": "л��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�㵴" ]), 	
(["quest_name": "��������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�㵴" ]), 	
(["quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�㵴" ]), 	
(["quest_name": "Գ����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"�㵴" ]), 	

(["quest_name": "���ϰ�", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"̫ԭ" ]), 	
(["quest_name": "�����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"̫ԭ" ]), 	
(["quest_name": "��", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"̫ԭ" ]), 	

(["quest_name": "�ϳ���", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	
(["quest_name": "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
	
([ "quest_name": "ʷ��ͷ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�°���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ͷ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "³����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	

([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "����ľ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	

([ "quest_name": "��ݼ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��Ϊ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�ﲮ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�販ʿ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
	
([ "quest_name": "Ү����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����ͨ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��ܽ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "ľ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "ƫ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�α�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����", "exp_bonus":random(10)+30,"pot_bonus": random(8)+10,"quest_city":"����" ]), 	
([ "quest_name": "����ϰ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
		
([ "quest_name": "�ƻ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�ɶ�" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�ɶ�" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�ɶ�" ]), 	
([ "quest_name": "���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�ɶ�" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�ɶ�" ]), 	
([ "quest_name": "�����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�ɶ�" ]), 	
([ "quest_name": "�˷��Ϸ���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�ɶ�" ]), 	

([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
([ "quest_name": "���ٴ�ʦ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	

([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����̩", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������ʿ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "ʿ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��ͷ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�̴�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����˾", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��Ů", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "�κ�ҩ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "Ѧ�ϰ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "ʯ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������ʿ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��˼��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������ʿ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "̫��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��Ů", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "��ũ�����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "����������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "�ϳ���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "��һ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����ʹ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�ų���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	
([ "quest_name": "�ſ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɽ" ]), 	

([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"Ȫ��" ]), 	
([ "quest_name": "��Ѷ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"Ȫ��" ]), 	

([ "quest_name": "��ʲ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
([ "quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	

([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"Ľ��ɽׯ" ]), 	
([ "quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"Ľ��ɽׯ" ]), 	

(["quest_name": "�粨��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "����ͬ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "�˰ٴ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	

(["quest_name": "�߾��ٱ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
(["quest_name": "�߾��佫", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	 	

(["quest_name": "���ɩ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"ʢ��" ]), 	
(["quest_name": "���ĳ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"ʢ��" ]), 	
(["quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"ʢ��" ]), 	
(["quest_name": "�����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"ʢ��" ]), 	
(["quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"ʢ��" ]), 	
		
(["quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "Ԫ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "�����ʦ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "��۴�ʦ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "Ԫ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "Ԫ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "Ԫ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "����ʦ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 		 
	
(["quest_name": "��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɳ" ]), 	
(["quest_name": "���ϰ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɳ" ]), 	
(["quest_name": "�δ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɳ" ]), 	
(["quest_name": "������Ů", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��ɳ" ]), 	
	
(["quest_name": "��С��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"���˹�" ]), 	
(["quest_name": "��ҩʦ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"���˹�" ]), 	
(["quest_name": "��Ƽ��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"���˹�" ]), 	
(["quest_name": "��С·", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"���˹�" ]), 	
	
(["quest_name": "��ľ��ӹ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "Ҷ��ʿ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
(["quest_name": "�·���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"������" ]), 	
	
(["quest_name": "�·���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�¼ұ�" ]), 	
(["quest_name": "�·���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�¼ұ�" ]), 	
(["quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"�¼ұ�" ]), 	
	
(["quest_name": "�����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��Զ" ]), 	
(["quest_name": "���Ͽ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��Զ" ]), 	
(["quest_name": "Ԭ���", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��Զ" ]), 	
(["quest_name": "�����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��Զ" ]), 	
(["quest_name": "�߾��ٱ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��Զ" ]), 	
(["quest_name": "�߾��佫", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"��Զ" ]),
	 	 	
(["quest_name": "��ͨ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
(["quest_name": "³��", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
(["quest_name": "���ı�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
(["quest_name": "����", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
(["quest_name": "�Դ�ƽ", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	 	
	
(["quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
(["quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
(["quest_name": "������", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
(["quest_name": "���ϰ�", "exp_bonus":random(20)+30,"pot_bonus": random(10)+10 ,"quest_city":"����" ]), 	
});

mixed rooms = ({
        ({
        "���ֹ㳡","����·","������","������Ϊ��","����������",
        "��΢��","����ƺ","��ѩɽɽ��","������","ȫ��̴���", 
        "Ĺ��","�һ�ɽׯ����","��ӹ��","������","���޺�", 
        "ѩɽ��ɽ��","һƷ�ô�Ժ","������ɽ��","�κϾ�","��ָ��", 
        "��ȸ����","��������","�׻�����","��������","�찲��",
        "�������","�����ھ�","�����","������","Ȫ������",
        "��������","�������","����¥","������","��ɽ����",                
        "�߹���","�����ַ�","��������","ϲ�ݳ�","��³��", 
        "����","ɽ����","����ͷ","��ͷɽ���","��ɽ����",
        "����Ժ","ӿȪ��","������","���Ϸ�","�Ͻ��",
        "�ɷ��","����ɽ��","������","����̶","���ɷ�",                
        "��Ӧ��","�����","������Ժ","������","������", 
        "��������","������","�һ�������","�嶾�̴���","������",
        "������","˿��֮·","��ͷɽ���","�ڷ��","���ŷ�",
        "�ϳ�","��Ҥ��","��Ȼ��","��ľ�沿��","��ľ��Ӫ��",
        "�ɹŲ�ԭ","���岿��","СϪ��","��Ҷ�㳡","���������",
        "������","���ݳ�","������","ɽ����","��ݮ��",
        "�����ַ�","ʮ�ֽ�ͷ","����������","�ָ�ʫ��","佻�Ϫ",
        "���Ӿ�¥","��ţ���","������","��گ�»���","������",
        "�����","���ƺ���","³����","ϲ�ݳ�","̫�ͽֿ�",
        "��³��","ʥ��","���ǹ�","��ѩɽ��´","���϶�",
        "������","ʮ����","��ɽ���","Ӣ�ۻ��","������",
        "�����ھ�","�����","��������լ","����ɽ����","��ˮ̶",
        "̫��","�����","������","��������","������",
        "������","ʥ����","�����ô���","����������","ƽ����",
        "���Է�","������","������","��������","������Ժ",
        "��̳��","��ȳ�","Ⱥ�ɹ�","������","ɯ��ƺ",
        "�����","����","�ƺӰ�կ��","������ԭ","���",
        "������ջ","������ջ","��ͩ԰���","����㳡","���ĵ�",
        "��ʦ��","�ɷ��","Ȫ������","��ӹ��","������Ժ",
        "��������","��ɽׯ","����ͤ","�Ͻ���","��ɽ��",
        "��ʶ�","��ڷ�","��ɽɽ��","����̨","�嶼����",
        "���׽���","������","���湬","����������","���칬",
        "�۾�¥","��ظ�ԭ","����ʹ����","����������","��ȸ������",
        "���¶�","��ң��","ѩɽ��ɽ��","ѩɽ��ɽ��","����̨",
        "�κϾ�","����ʮ�ֽ�ͷ","�������","����Ժ","������",
        "����ɽ��","�չ���","����������","ף�ڵ�","������",
        "��翷�ɽ��","������","��ɽ����","����ɽ��","ӭ��Ƶ�",
        "��ָ��","��ָ��","������","Ĵָ��","̫�׾�¥",
        "ʢ������","������","���س�����","���Ṭ","���տ���ɽ",
        "�ϳ���","��ӹ��","����Ͽ","ů��","�ʹ�����",
        "�����","ϲ����","ӭ��¥","����","������",
        "������","��Ĺ�ڲ�","ϲ����","ӭ��¥","���岿��",
        "���س�����","�Ϸʹ㳡","�Ž��㳡","����㳡","���ݶ���",
        "��������","�껨̨","�Ӹ���","�����ͷ","���չ�¥",
        "��������","�˽ǽ�","������������","������","�����ĳ�",
        "��ɳ�㳡","�ϲ��㳡","����ʮ�ֽ�ͷ","�̼���","������",
        }),
        });

mixed names = ({
        ({
        "���ֹ㳡","����·","������","������Ϊ��","����������",
        "��΢��","����ƺ","��ѩɽɽ��","������","ȫ��̴���", 
        "Ĺ��","�һ�ɽׯ����","��ӹ��","������","���޺�", 
        "ѩɽ��ɽ��","һƷ�ô�Ժ","������ɽ��","��ָ��", "�����",
        "��ȸ����","��������","�׻�����","��������","�찲��",
        "�¼�����","�����ھ�","�����","������","Ȫ������",
        "��������","�������","����¥","������","��ɽ����",                
        "�߹���","�����ַ�","��������","ϲ�ݳ�","��³��", 
        "����","ɽ����","����ͷ","��ɽ����","����С��",
        "����Ժ","ӿȪ��","������","���Ϸ�","�Ͻ��",
        "�ɷ��","����ɽ��","������","����̶","���ɷ�",                
        "��Ӧ��","�����","������Ժ","������","������", 
        "��������","������","�����޹�","���","������",
        "������","˿��֮·","�ڷ��","���ŷ�","������",
        "�ϳ�","��Ȼ��","��ľ�沿��","��ľ��Ӫ��","�ڷ��",
        "�ɹŲ�ԭ","���岿��","СϪ��","��Ҷ�㳡","���������",
        "������","���ݳ�","������","��ݮ��","��ɺӱ�",
        "�����ַ�","ʮ�ֽ�ͷ","����������","�ָ�ʫ��","佻�Ϫ",
        "��ţ���","������","��گ�»���","������","����",
        "�����","���ƺ���","³����","ϲ�ݳ�","̫�ͽֿ�",
        "��³��","ʥ��","���ǹ�","��ѩɽ��´","���϶�",
        "������","ʮ����","��ɽ���","Ӣ�ۻ��","������",
        "�����ھ�","�����","��������լ","����ɽ����","��ˮ̶",
        "̫��","�����","������","��������","������",
        "������","ʥ����","�����ô���","����������","ƽ����",
        "������","������","��������","������Ժ","��ͤ",
        "��̳��","��ȳ�","Ⱥ�ɹ�","������","ɯ��ƺ",
        "�����","����","�ƺӰ�կ��","������ԭ","���",
        "������","������ջ","��ͩ԰���","����㳡","���ĵ�",
        "��ʦ��","�ɷ��","Ȫ������","��ӹ��","������Ժ",
        "��������","��ɽׯ","����ͤ","�Ͻ���","��ɽ��",
        "��ʶ�","��ڷ�","��ɽɽ��","����̨","������",
        "���׽���","������","���湬","����������","���칬",
        "�۾�¥","��ظ�ԭ","����ʹ����","����������","��ȸ������",
        "���¶�","��ң��","ѩɽ��ɽ��","ѩɽ��ɽ��","����̨",
        "����Է","����ʮ�ֽ�ͷ","�������","����Ժ","������",
        "����ɽ��","�չ���","ȫ��̴���","ף�ڵ�","������",
        "��翷�ɽ��","������","������ɽ��","ӭ��Ƶ�","�����",
        "��ָ��","��ָ��","������","Ĵָ��","̫�׾�¥",
        "ʢ������","������","���Ṭ","���տ���ɽ","����Ͽ",
        "��ӹ��","����Ͽ","ů��","�ʹ�����","�����",
        "�����","ϲ����","ӭ��¥","����","������",
        "������","��Ĺ�ڲ�","ϲ����","ӭ��¥","���岿��",
        "���س�����","�Ϸʹ㳡","�Ž��㳡","����㳡","���ݶ���",
        "��������","�껨̨","�Ӹ���","�����ͷ","���չ�¥",
        "��������","�˽ǽ�","������������","������","�����ĳ�",
        "��ɳ�㳡","�ϲ��㳡","����ʮ�ֽ�ͷ","�̼���","������",
        }),
        });
void init()
{
        add_action("give_quest", "quest");
        add_action("give_job", "job");
        add_action("give_job", "liangong");
        add_action("ask_jianxi", "teamjob");
        
}


int give_job()
{      
        mapping changxi,changxiwhere;
        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("obj/liangong")>0)
    {
                tell_object(me,"��ȥ�������(duilian)�ɡ����书����,����š�\n");
                return 1;
    } 



message_vision("$N����$n˵������ȥ��һ��"+this_object()->query("mp")+"�ĵ��ӻ������(duilian)һ�°ɡ�\n", this_object(), me);
        me->set_temp("obj/liangong", 8);
        //me->set_temp("obj/menpai",changxiwhere);
        return 1;   
}


int give_quest()
{
        object letter,ob,room2;
        mapping quest,item,npc,quests;
        object me;
        int j, combatexp, timep,factor,num,k,k1;
        string room;
string file;
string *roomlines;
string location,local,fname;
string *dir2;

        string tag = "2000000";
        string *levels = ({
                        "10000",
                        "15000",
                        "20000",
                        "30000",
                        "50000",
                        "80000",
                        "100000",
                        "130000",
                        "170000",
                        "220000",
                        "300000",
                        "450000",
                        "600000",
                        "800000",
                        "1000000",
                        "2000000"
        });


        me = this_player();
        combatexp = (int) (me->query("combat_exp"));



        
                if(me->query_temp("jobitem"))
        {
tell_object(me,"\n����ʹЦ��˵�������ȰѸղ������ҵĶ����ҵ����˼Ұ�....��\n");
             return 1;
        }
                if(me->query_temp("roomjob"))
        {
tell_object(me,"\n����ʹЦ��˵�������ȰѴ�̽�������ð�....��\n");
             return 1;
        }


if (me->is_busy() || this_object()->is_busy())
        {
tell_object(me,"\n����ʹЦ��˵������æ����....��\n");
             return 1;
        }

	  if (me->query("mjb2job") )
	  
{
tell_object(me,"\n����ʹ˵�������������Ҫ"+me->query("mjb2job")+"��������?....��\n");
             return 1;

}


        //if ((int)me->query_condition("roomjob")){message_vision("$N����$nҡ��ҡͷ˵����սӹ���̽����!�Ȼ�����!\n", this_object(), me);return 1;}



        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵�����æ��,�Ȼ�����!\n", this_object(), me);
                      return 1;
            }
        if(combatexp<10000)
        {
tell_object(me,"\n����ʹЦ��˵��������书������....��\n");
             return 1;

        }

        if ((int)me->query("age")<=14 && !me->query("zhuanshen")  && me->query("combat_exp",1)<=200000 && me->query("nbjob")!=37)  
            {
                      message_vision("$N����$nҡ��ҡͷ˵���㻹̫С�����������������(help geren)!\n", this_object(), me);
                      return 1;
            }


        if((quest =  me->query("quest")))
        {
             if( ((int) me->query("task_time")) >  time() )
             {
tell_object(me,"����ʹ������һ��˵�����Ҹղ�Ҫ�����������أ�\n");
                  // me->set_temp("menpaijob",0);
                  // me->delete_temp("menpaijob");
                   return 0;
             }
             else
             {
             	  	message_vision("$N����$nҡ��ҡͷ˵������²���,�Ȼ�����!\n", this_object(), me);
                 	
                 	me->apply_condition("menpai_busy",2+random(3));
                 	me->set_temp("menpaijob",0);
                   	me->delete_temp("menpaijob");
                   	me->set("quest",0);
                   	return 0;

             }
             
             
        }

 this_object()->start_busy(2);
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
             combatexp=combatexp/3;
             if( atoi(levels[j])  <= combatexp )
             {
                   num=j;
                   factor=10;
                   break;
             }
        }
        if (num>0)
        {
             if (random(50)>45)
             {
                   num=num-1;
             }
        } 
        else
        {
             if ((num<sizeof(levels)-1)&&(random(100)>95))
             {
                   num=num+1;
                   factor=15;
             }
        }
        tag=levels[num];

 tag=levels[num];
me->add_temp("mpjobn1",1);
me->add_temp("nbjob36",1);
me->set_temp("menpaikill",1);
me->apply_condition("menpai_busy",3);
//��������ʼ
 k=2;
 if (me->query_temp("menpaijob") >= 6 && me->query("combat_exp",1) < 2000000)
 {
k=6;
}

k1=3;
 if (me->query_temp("menpaijob") >= 10 && me->query("combat_exp",1) < 5000000)
 {
k1=6;
}
me->set("quest",0);
me->delete("quest");
me->delete("songxin");
        if (random(5) == 0 || (me->query("combat_exp") < 2000000 && random(k)==0))
        {
        //quest = lquest[random(sizeof(lquest))];
if (me->query("combat_exp",1) <=2000000)
quest = lquest1[random(sizeof(lquest1))];
else if (me->query("combat_exp",1) <=4000000)
quest = lquest2[random(sizeof(lquest2))];
else if (me->query("combat_exp",1) <=6000000)
quest = lquest3[random(sizeof(lquest3))];
else if (me->query("combat_exp",1) <=8000000)
quest = lquest4[random(sizeof(lquest4))];
else if (me->query("combat_exp",1) > 8000000)
quest = lquest[random(sizeof(lquest))];

//quest = lquest1[random(sizeof(lquest1))];
        timep = random(100) + 380;
        time_period(timep, me);
        tell_object(me, "����" + quest["quest_city"] + "������,�����͸���" + quest["quest_name"] + "��������������ˡ�\n" NOR);
        message_vision("$N����$nһ���š�\n",this_object(),me);
        if (ob = present("xin", this_player()))
         {
             message_vision("����ʹ����ǰ�������˻�ȥ��\n",me);
             me->delete_temp("menpaijob");
             destruct(ob);
             letter = new("/quest/menpai/letter");
                letter->set("long", "����һ��д��" + quest["quest_city"] + "������" +quest["quest_name"] + 
                                    "���ױ��ź����������songxin <id>���͸����ˡ�\n"); 
             letter->move(me);
             quest["quest_type"] = "�����͸�";
             quest["exp_bonus"] = quest["exp_bonus"];
             quest["pot_bonus"] = quest["pot_bonus"];
             quest["score"] = 0;
             me->set("quest", quest);
             me->set("songxin",1);
             me->set("task_time", (int)time() + timep);
             me->set("quest_factor", factor);
             me->set("last_task_time", time());
             return 1;     
         }
         else
         {
            letter = new("/quest/menpai/letter");
                letter->set("long", "����һ��д��" + quest["quest_city"] + "������" + quest["quest_name"] + 
                                    "���ױ��ź����������songxin <id>���͸����ˡ�\n"); 
            letter->move(me);
            quest["quest_type"] = "�����͸�";
            quest["exp_bonus"] = quest["exp_bonus"];
            quest["pot_bonus"] = quest["pot_bonus"];
            quest["score"] = 0;
            me->set("quest", quest);
            me->set("songxin",1);
            me->set("task_time", (int)time() + timep);
            me->set("quest_factor", factor);
            me->set("last_task_time", time());
if (me->query_temp("menpaijob") <= 0)
me->delete_temp("menpaijob");


if ((int)me->query_temp("menpaijob") >= 30 && random(6)==0  && (int)me->query("mpgx") < 18)
{
me->add("mpgx",1);
tell_object(me,"�����Ĳ���������ɹ��׶�������!\n" NOR);
tell_object(me,"ĿǰΪֹ,������ɹ��׶�Ϊ��"HIC+chinese_number(me->query("mpgx"))+NOR"����\n" NOR);
}

if (me->query_temp("menpaijob") > 1)
tell_object(me,"���Ѿ�����Ϊ�������ˡ�"HIC+chinese_number(me->query_temp("menpaijob"))+NOR"���������ˡ�\n" NOR);
         }
return 1;
}
else        if (random(5) == 0 || (me->query("combat_exp") < 5000000 && random(k1)==0))
{
	  //room=rooms[0][random(sizeof(rooms[0]))];
	file = read_file("/clone/medicine/dynamic_location");
	if (me->query("combat_exp",1)<=2000000)
	file = read_file("/clone/medicine/dynamic_location1");
	else if (me->query("combat_exp",1)<=4000000)
	file = read_file("/clone/medicine/dynamic_location2");
	else if (me->query("combat_exp",1)<=6000000)
	file = read_file("/clone/medicine/dynamic_location3");
else if (me->query("combat_exp",1)<=8000000)
	file = read_file("/clone/medicine/dynamic_location4");
else if (me->query("combat_exp",1)>8000000)
	file = read_file("/clone/medicine/dynamic_location5");

if (!file)
	file = read_file("/clone/medicine/dynamic_location");
	
	roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
if (!room2)
{
	file = read_file("/clone/medicine/dynamic_location");
	roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
}
local=room2->query("short");
if (!local)
{
	file = read_file("/clone/medicine/dynamic_location");
	roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
}
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;

        quest = lquest[random(sizeof(lquest))];
        //timep = 300+random(300)+10;
        //time_period(timep, me);
             quest["quest_type"] = "��̽";
             quest["quest"]=local;
             quest["exp_bonus"] = 30;
             quest["pot_bonus"] = 30;
             quest["time"]=600;
             quest["score"] = 10;
//me->set("quest",0);
//me->delete("quest");
            me->set("quest", quest);
            me->set("task_time", (int)time() + 600);
            me->set("quest_factor", 15);
            me->set("last_task_time", time());
         me->apply_condition("roomjob",10);
	         me->set_temp("roomjob",local);

	  
	  tell_object(me,HIC"����ʹ˵:����˵�ڡ�"HIR+room+HIC"����������һЩ�����¼���"+
           "��Ͽ�ȥ��"HIR+local+HIC"����̽(citan)һ�°ɡ�\n"NOR);
if (wizardp(me))
	  tell_object(me,GRN"WIZ��Ϣ:��̽λ�á�"YEL+fname+GRN"����\n"NOR);

if (me->query_temp("menpaijob") <= 0)
me->delete_temp("menpaijob");

if (me->query_temp("menpaijob") > 1)
tell_object(me,"���Ѿ�����Ϊ�������ˡ�"HIC+chinese_number(me->query_temp("menpaijob"))+NOR"���������ˡ�\n" NOR);
if ((int)me->query_temp("menpaijob") >= 10 && random(8)==0  && (int)me->query("mpgx") < 18)
{
me->add("mpgx",1);
tell_object(me,"�����Ĳ���������ɹ��׶�������!\n" NOR);
tell_object(me,"ĿǰΪֹ,������ɹ��׶�Ϊ��"HIC+chinese_number(me->query("mpgx"))+NOR"����\n" NOR);
}
return 1;
}
else


        if (random(5) == 0 )
        {
     quest = QUESTS_D(tag)->query_quest();
	}
       else
        if (random(5) == 1 )
        {
     quest = QUESTH_D(tag)->query_quest();
	}
       else
        if (random(5) == 2 )
        {
     quest = QUESTW_D(tag)->query_quest();
	}
       else if (random(16)==0 )
{
item  = QUESTW_D(tag)->query_quest();
npc = QUESTS_D(tag)->query_quest();
if (random(2)==1)
npc = QUESTH_D(tag)->query_quest();
 quest = lquest[random(sizeof(lquest))];
 if (me->query("combat_exp",1) <=2000000)
quest = lquest1[random(sizeof(lquest1))];
else if (me->query("combat_exp",1) <=4000000)
quest = lquest2[random(sizeof(lquest2))];
else if (me->query("combat_exp",1) <=6000000)
quest = lquest3[random(sizeof(lquest3))];
else if (me->query("combat_exp",1) <=8000000)
quest = lquest4[random(sizeof(lquest4))];
else if (me->query("combat_exp",1) > 8000000)
quest = lquest[random(sizeof(lquest))];

             quest["quest_type"] = "��"+item["quest_city"]+"�ҵ�"+item["quest"]+"Ȼ��"+npc["quest_city"]+"��";
             quest["quest"]=npc["quest"];
             quest["exp_bonus"] = 30;
             quest["pot_bonus"] = 30;
             quest["time"]=800;
             quest["score"] = 10;
            me->set("quest", quest);
            me->set("task_time", (int)time() + 800);
            me->set("quest_factor", 15);
            me->set("last_task_time", time());
me->set_temp("jobitem",item["quest"]);
me->set_temp("jobnpc",npc["quest"]);
me->apply_condition("roomjob",8);
tell_object(me,HIC"����ʹ˵��������ҵ�"+item["quest_city"]+"�ѡ�"HIG+item["quest"]+HIC"���ҵ�������"+npc["quest_city"]+"������"HIG+npc["quest"]+HIC"����\n" NOR);
if (me->query_temp("menpaijob") <= 0)
me->delete_temp("menpaijob");
//me->add_temp("menpaijob",1);
if (me->query_temp("menpaijob") > 1)
tell_object(me,"���Ѿ�����Ϊ�������ˡ�"HIC+chinese_number(me->query_temp("menpaijob"))+NOR"���������ˡ�\n" NOR);
if ((int)me->query_temp("menpaijob") >= 6 && random(8)==0  && (int)me->query("mpgx") < 18)
{
me->add("mpgx",1);
tell_object(me,"�����Ĳ���������ɹ��׶�������!\n" NOR);
tell_object(me,"ĿǰΪֹ,������ɹ��׶�Ϊ��"HIC+chinese_number(me->query("mpgx"))+NOR"����\n" NOR);
}

return 1;
}
else
	{
quest = QUESTW_D(tag)->query_quest();
}
//tell_object(me,tag);
//if (!quest) quest = QUESTW_D(tag)->query_quest();

//tell_object(me,quest["quest_type"]);
//tell_object(me,quest["quest"]);
        timep = quest["time"];
        if (!quest["time"]) timep=600;
        timep = timep+360;
        time_period(timep, me);
        if(quest["quest_type"]=="ɱ")
             tell_object(me,"��"+quest["quest_city"]+"�ѡ�"HIR+quest["quest"]+HIC"��ɱ�ˣ����Ա��ɲ�����\n" NOR);
        else
             tell_object(me,"��"+quest["quest_city"]+"���� �һء�"HIG+quest["quest"]+HIC"������Ա������á�\n" NOR);
if (me->query_temp("menpaijob") <= 0)
me->delete_temp("menpaijob");

if (me->query_temp("menpaijob") > 1)
tell_object(me,"���Ѿ�����Ϊ�������ˡ�"HIC+chinese_number(me->query_temp("menpaijob"))+NOR"���������ˡ�\n" NOR);

if ((int)me->query_temp("menpaijob") >= 6 && random(8)==1 && (int)me->query("mpgx") < 18)
{
me->add("mpgx",1);
tell_object(me,"�����Ĳ���������ɹ��׶�������!\n" NOR);
tell_object(me,"ĿǰΪֹ,������ɹ��׶�Ϊ��"HIC+chinese_number(me->query("mpgx"))+NOR"����\n" NOR);
}

             quest["time"]=300;
             quest["exp_bonus"]=260+(int)me->query_temp("menpaijob");
             quest["pot_bonus"]=180+me->query_temp("menpaijob")/2;
             quest["score"]=50;
        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]+180);
       
        return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        tell_object(me,HIC "����ʹ˵�����������" + time + "��");
        return 1;
}

int accept_object(object who, object ob)
{
        int bonus, exp, pot, score,a;
        string test;
        mapping quest;
        object ob1;
        if (ob->query("money_id"))
        {
        	

             if(!who->query("quest") && !who->query_temp("jobitem") && !who->query_temp("roomjob"))
             {
                  tell_object(who,"û�ҵ��������������������ĵ��Ӱ�æ���ˣ�\n");
                   return 1;
             }
       if ( ob->value() < 2000)
             {
tell_object(who,"����ʹ���˿�$P��������Ǯ˵����̫���ˣ���ô����Ҳ����˼�ó��֣�\n");
                   return 1;
             }
             else
             {



tell_object(who,"����ʹ˵�����ðɣ���ξ����ˣ��²�Ϊ����\n");
                   who->set_temp("menpaijob",0);
                   who->set_temp("menpaijob",0);
                   who->delete_temp("menpaijob");
                who->delete_temp("jobitem");
                who->delete_temp("roomjob");
                   who->apply_condition("menpai_busy",8+random(8));who->delete_temp("menpaijob");
                   who->delete_temp("menpaijob");
                   who->set("quest",0);
                   who->delete("songxin");
                   who->set_temp("mpjobn1",0);
                   who->set_temp("mpjobn2",0);
                   who->delete_temp("mpjobn1");
who->delete_temp("mpjobn2");
if (who->query("mjb2job"))
{
who->set("mjb2job",0);
who->delete("mjb2job");
if (who->query("mpgx",1)>=10)
{
who->apply_condition("menpai_busy",20);
who->add("mpgx",-1);	
}	
}
         return 1;
        }
        }
        if(!(quest = who->query("quest")))
        {
             tell_object(who,"����ʹ˵�������㶺�ˣ���Ҫ�Ĳ��������\n");
             return 0;
        }

        if( ob->query("name") != quest["quest"])
        {
        tell_object(who,"����ʹ��ð���ɣ�����ʲô������Ŀ����ѽ�����������Ϸ��ˣ�\n");
        return 0;
        }

        if ((int) who->query("task_time") < time() )
        {
             tell_object(who,"����ʹ˵�����Բ���ʱ����ˣ���ĵ��Ӹհѻ�������ˣ�\n");
             destruct(ob);
             return 0;
        }
        else
        {
             tell_object(who,"����ʹ���˵�˵����̫���ˣ��Ҿ���Ҫ����������б��£�\n");
             exp = 150 + random(100)+(int)who->query_temp("menpaijob")/2;
             pot = 120 + random(30)+(int)who->query_temp("menpaijob")/3;
             score = 12 + random(5);

             bonus = (int) who->query("combat_exp");
             bonus += exp;
             who->set("combat_exp", bonus);
             bonus = (int) who->query("potential");
             bonus = bonus - (int) who->query("learned_points");
             bonus = bonus + pot;
             bonus += (int) who->query("learned_points");
             who->set("potential", bonus );
             bonus = (int) who->query("score");
             bonus += score;
             who->set("score", bonus);
             tell_object(who,HIW"��ϲ�������һ������\n"NOR);
             tell_object(who,HIW"�㱻�����ˣ�" + chinese_number(exp)
               + "��ʵս���飬\n"+ chinese_number(pot) + "��Ǳ�ܣ�\n"
               + chinese_number(score)+"�㽭��������\n"NOR);
             who->set("quest", 0 );
who->add_temp("menpaijob",1);
who->delete_temp("menpaikill");
a=random(3000)+1000;

if (a> 10 && random(10)==0) 
{	
exp=(int)a/10+10;
pot=(int)exp*2/3+10;

        
addnl(who,"exp",exp);
//        tell_object(who,  "��ľ���������" + chinese_number(exp) + "��Ǳ��������"+chinese_number(pot) +
//                         "��\n" NOR);

}
call_out("destroying", 1, ob, this_object(), who); 
//destruct(ob);
             return 1;
}
//destruct(ob);
        return 1;
}

void destroying(object obj, object ob, object me)
{   
   
   destruct(obj);
   return;      
}        
        
string ask_jianxi()
{     object guo,ob,me,room2,kill,obhs,mijian;
      object *team;
      int i=0,count=0,minexp,maxexp,ttype,rd;
      int wgdj;
      string where;
        string room;
string file;
string *roomlines;
string location,local,fname;
string *dir2;
mapping quest;
	  guo =this_object();
	  ob=this_player();
	  me=this_player();


        if ((int)me->query_condition("menpai_busy")  && !wizardp(ob))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵�����æ��,�Ȼ�����!\n", this_object(), me);
                      return "�Ȼ�������";
            }
	  if (ob->query("mjb2job")  && !wizardp(ob))
	  
{
tell_object(me,"�ϴθ���������������\n" NOR);

	  return "��Ȼ������ɡ�";
}


        if ((int)me->query("combat_exp",1)<=1000000 || (int)me->query_skill("force",1) < 200 )  
            {
                      message_vision("$N����$nҡ��ҡͷ˵���㻹̫С�����������������(help geren)!\n", this_object(), me);
                       return "���书�ߵ������ɡ�";
            }


if (guo->is_busy())
{
                      message_vision("$N����$nҡ��ҡͷ˵��������æ!\n", this_object(), me);
                       return "������æ��";
	
	
}
	  
	  if (ob->query_condition("mjb2_busy")  && !wizardp(ob))
	  
{
tell_object(me,"��ʱû������\n" NOR);

	  return "��û���յ��κ���Ϣ����ȥ����������һ�°ɡ�";
}

        if((quest =  me->query("quest"))  && !wizardp(me) )
        {
             if( ((int) me->query("task_time")) >  time()  && !wizardp(me))
             {
tell_object(me,"����ʹ������һ��˵�����Ҹղ�Ҫ�����������أ�\n");
                  // me->set_temp("menpaijob",0);
                  // me->delete_temp("menpaijob");
                   return "�Ȼ������ɡ�";
             }
             else
             {
             	  	message_vision("$N����$nҡ��ҡͷ˵������²���,�Ȼ�����!\n", this_object(), me);
                 	
                 	me->apply_condition("menpai_busy",2+random(3));
                 	me->set_temp("menpaijob",0);
                   	me->delete_temp("menpaijob");
                 	me->set_temp("menpaijob2",0);
                   	me->delete_temp("menpaijob2");
                   	me->set("quest",0);
                   	return "�Ȼ������ɡ�";

             }
             
             
        }


	  if ((int)ob->query_temp("menpaijob")<=1 && !wizardp(ob))
{
tell_object(me,"�����ж�����������(quest)�����������˵�ɡ�\n" NOR);

	  return "����������������������ɡ�";
}	  	



	  
seteuid(geteuid(guo));


	file = read_file("/clone/medicine/dynamic_location");
	if (me->query("combat_exp",1)<=2000000)
	file = read_file("/clone/medicine/dynamic_location1");
	else if (me->query("combat_exp",1)<=4000000)
	file = read_file("/clone/medicine/dynamic_location2");
	else if (me->query("combat_exp",1)<=6000000)
	file = read_file("/clone/medicine/dynamic_location3");
else if (me->query("combat_exp",1)<=8000000)
	file = read_file("/clone/medicine/dynamic_location4");
else if (me->query("combat_exp",1)>8000000)
	file = read_file("/clone/medicine/dynamic_location5");

if (!file)
	file = read_file("/clone/medicine/dynamic_location");
	
	roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
if (!room2)
{
	file = read_file("/clone/medicine/dynamic_location");
	roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
}
local=room2->query("short");
if (!local)
{
	file = read_file("/clone/medicine/dynamic_location");
	roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
}
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;

//location Ϊ��ַ
//room Ϊ����
//localΪroom����
//room="��Ĺ�ɵ�С��";
//local="С��";
//location="/d/gumu/xiaoting";
//�ο����force�ȼ�
//wgdj=(int)me->query_skill("force",1);

me->apply_condition("menpai_busy",3);
me->start_busy(3);
guo->start_busy(3);
me->add_temp("mpjobn2",1);
      ttype=random(6);
      //ttype=4;
      if (ttype==0)
      {
      //��������	
            team=ob->query_team();
      count=sizeof(team);
      if(count>3)
{
tell_object(me,"����������������ִ�С�\n" NOR);
	  return "���²������"; //too many people
}      

if(count>1)
{
minexp=ob->query("combat_exp");
	  maxexp=minexp;
      
	  for(i=1;i<count;i++)
      { if(team[i]!=0)
	  { if(team[i]->query("combat_exp")<minexp)
	    minexp=team[i]->query("combat_exp");
		if(team[i]->query("combat_exp")>maxexp)
        maxexp=team[i]->query("combat_exp");
	  }
	  }
	  if ((maxexp-minexp)>2000000)
tell_object(me,"�����е����书���̫�����ˡ�\n" NOR);
      return "���ǵ��书���̫���⡣";//exp too far
}
if (count>1)
{
for(i=1;i<count;i++)
{
team[i]->apply_condition("mjb2_busy",38);	
}	      
}
if (count<1) count=1;
if (!count) count=1;
me->apply_condition("mjb2_busy",38);		
me->set("quest/quest_type", "����");
me->set("quest/quest", "���ָ���"+room);	
me->set("quest/quest_name", "����:"+room);
me->set("task_time", time() + 1080);
me->set("mjb2job","����");
me->set_temp("team_count",count);
	
      me->start_busy(3);
                command("blow " + me->query("id"));
tell_object(me,"������λ��ͣ���Ҫ���͵�"+room+"ȥ��\n·�ϻ��е���׷ɱ��һ��Ҫ��֤�����͵��� ����������˸��֣���ɱ���ۡ�\n" NOR);
                obhs = new("/quest/menpai/hsnpc",1);
                obhs->move(environment(guo));

obhs->set("title",me->query("family/family_name"));
obhs->set("hsr",me->query("id"));
obhs->set_leader(me);
me->apply_condition("mp2_kill",18);
obhs->set("combat_exp", me->query("combat_exp"));
obhs->set("hstarget",local);	
obhs->set("hsfile",location);
me->set_temp("mjb2jobt",location);
return  "������̰�!";//too low exp
      }	
      else if (ttype==1)
      {
      //Ѳ������	
room="";
	file = read_file("/clone/medicine/dynamic_location1");
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
me->set("quest/location1", location);
me->set("quest/location1n", local);

	file = read_file("/clone/medicine/dynamic_location2");
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=room+":"+zuji(dir2[1])+local;
me->set("quest/location2", location);
me->set("quest/location2n", local);
        file = read_file("/clone/medicine/dynamic_location3");
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
me->set("quest/location3", location);
me->set("quest/location3n", local);
room=room+":"+zuji(dir2[1])+local;

      team=me->query_team();
      count=sizeof(team);
      if(count>3)
{
tell_object(me,"����������������ִ�С�\n" NOR);
	  return "���²������"; //too many people
}      

if(count>1)
{
minexp=ob->query("combat_exp");
	  maxexp=minexp;
      
	  for(i=1;i<count;i++)
      { if(team[i]!=0)
	  { if(team[i]->query("combat_exp")<minexp)
	    minexp=team[i]->query("combat_exp");
		if(team[i]->query("combat_exp")>maxexp)
        maxexp=team[i]->query("combat_exp");
	  }
	  }
	  if ((maxexp-minexp)>2000000)
tell_object(me,"�����е����书���̫�����ˡ�\n" NOR);
      return "���ǵ��书���̫���⡣";//exp too far
}
if (count>1)
{
for(i=1;i<count;i++)
{
team[i]->apply_condition("mjb2_busy",38);	
}	      
}
if (count<1) count=1;
if (!count) count=1;	      

me->apply_condition("mjb2_busy",38);	

me->set("quest/quest_type", "Ѳ��");
me->set("quest/quest", room);	
me->set("quest/quest_name", "Ѳ��:"+room);
me->set("task_time", time() + 1080);
me->set("mjb2job","Ѳ��");
me->set_temp("team_count",count);
tell_object(me,"�㰴�Ⱥ�˳��ȥѲ��һ��"+room+"�ɡ�\n" NOR);
if (wizardp(me))
tell_object(me,"λ��:"+me->query("quest/location1")+":"+me->query("quest/location2")+":"+me->query("quest/location3")+"��\n" NOR);
	  return "����С�ĵ���ɱ�ֺ͵������������ָ���!";

      	
      }	
      else if (ttype==2)
      {
      //�ᱦ����	
room="";
rd=random(3);
	file = read_file("/clone/medicine/dynamic_location1");
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
local=room2->query("short");
if (rd==0) 
{
                obhs = new("/quest/menpai/baowu",1);
                obhs->move(room2);
                zujinpc(me,obhs);
                mijian=new("/quest/menpai/mijian",1);
                mijian->move(obhs);
                mijian->set("okname",me->query("id"));
                //obhs->random_move();
                me->set("quest/location", location);
}	

dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;


	file = read_file("/clone/medicine/dynamic_location2");
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
if (rd==1) 
{
                obhs = new("/quest/menpai/baowu",1);
                obhs->move(room2);
                zujinpc(me,obhs);
                mijian=new("/quest/menpai/mijian",1);
                mijian->move(obhs);
                mijian->set("okname",me->query("id"));
                //obhs->random_move();
                me->set("quest/location", location);
}
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=room+":"+zuji(dir2[1])+local;

        file = read_file("/clone/medicine/dynamic_location3");
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
if (rd==2) 
{
                obhs = new("/quest/menpai/baowu",1);
                obhs->move(room2);
                zujinpc(me,obhs);
                mijian=new("/quest/menpai/mijian",1);
                mijian->move(obhs);
                mijian->set("okname",me->query("id"));
                //obhs->random_move();
me->set("quest/location", location);

}
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=room+":"+zuji(dir2[1])+local;

      team=me->query_team();
      count=sizeof(team);
      if(count>3)
{
tell_object(me,"����������������ִ�С�\n" NOR);
	  return "���²������"; //too many people
}      

if(count>1)
{
minexp=ob->query("combat_exp");
	  maxexp=minexp;
      
	  for(i=1;i<count;i++)
      { if(team[i]!=0)
	  { if(team[i]->query("combat_exp")<minexp)
	    minexp=team[i]->query("combat_exp");
		if(team[i]->query("combat_exp")>maxexp)
        maxexp=team[i]->query("combat_exp");
	  }
	  }
	  if ((maxexp-minexp)>2000000)
tell_object(me,"�����е����书���̫�����ˡ�\n" NOR);
      return "���ǵ��书���̫���⡣";//exp too far
}
if (count>1)
{
for(i=1;i<count;i++)
{
team[i]->apply_condition("mjb2_busy",38);	
}	      
}
if (count<1) count=1;
if (!count) count=1;	      

me->apply_condition("mjb2_busy",38);	

me->set("quest/quest_type", "�ᱦ");
me->set("quest/quest", room);	
me->set("quest/quest_name", "�ᱦ:"+room);
me->set("task_time", time() + 1080);
me->set("mjb2job","�ᱦ");
me->set_temp("team_count",count);

	
      //me->start_busy(3);

tell_object(me,"�������������ܼ����ڵ������� ��˵�����п�����"+room+"���������˵����ֽ�"+obhs->query("name")+"��\n" NOR);
if (wizardp(me))
tell_object(me,"λ��:"+me->query("quest/location")+":"+obhs->query("id")+"��\n" NOR);


	  return "ȥ�������ܼ��ҵ��ɡ�";

      	
      }	
      else if (ttype==3)
      {
      //�������	

      team=ob->query_team();
      count=sizeof(team);
	 // write("\n"+sprintf("%d",count));

	  minexp=ob->query("combat_exp");
	  maxexp=minexp;destruct(present("mi jian",ob));

      if(count>3)
{
tell_object(me,"����������������ִ�С�\n" NOR);
	  return "���²������"; //too many people
}   
	  if (ob->query_condition("mjb2_busy") && !wizardp(me)) 
	  {
	  tell_object(me,"��û���յ��κ���Ϣ��\n" NOR);
	  return "�Ȼ������ɡ�";
      }
	 

if(count>1)
{
minexp=ob->query("combat_exp");
	  maxexp=minexp;
      
	  for(i=1;i<count;i++)
      { if(team[i]!=0)
	  { if(team[i]->query("combat_exp")<minexp)
	    minexp=team[i]->query("combat_exp");
		if(team[i]->query("combat_exp")>maxexp)
        maxexp=team[i]->query("combat_exp");
	  }
	  }
	  if ((maxexp-minexp)>2000000)
tell_object(me,"�����е����书���̫�����ˡ�\n" NOR);
      return "���ǵ��书���̫���⡣";//exp too far
}
if (count>1)
{
for(i=1;i<count;i++)
{
team[i]->apply_condition("mjb2_busy",38);	
}	      
}
if (count<1) count=1;
if (!count) count=1;	      

me->apply_condition("mjb2_busy",38);	

me->set("quest/quest_type", "���");
me->set("quest/quest", local);	
me->set("quest/quest_name", "���:"+room);
me->set_temp("tjob",local);
me->set("task_time", time() + 1080);
me->set("mjb2job","���");
me->set_temp("team_count",count);


         me->apply_condition("mptjob",23);
message_vision("�Ҹյõ���Ϣ����һ����ɵ������������ԡ��ɼ�ϸ͵ȥ�����ɵĻ�Ҫ�ļ�\n"+
		        "���ǸϿ�ȥ"+room+"�����أ�������ȫ�����������ļ���͵�����(xiaohui)��\n"+
			    "�϶����в��ٱ��ɵ��ӽ�Ӧ�������С�ġ�\n", this_object(), me);

if (wizardp(me))
tell_object(me,"λ��:"+location+"��\n" NOR);


	  return    "��ȥ�ɡ�";      	
      }	
      else if (ttype==4)
      {
      //�������	
room="";
rd=random(2);
	file = read_file("/clone/medicine/dynamic_location1");
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);

                obhs = new("/quest/menpai/boss2",1);
                obhs->move(room2);
obhs->set("killbyn",me->query("id"));
zujinpc(me,obhs);
me->set("quest/location", location);

local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;

	file = read_file("/clone/medicine/dynamic_location5");
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
me->set("quest/location1", location);


local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
me->set("quest/location1", location);
me->set("quest/location1n", zuji(dir2[1])+local);


      

      team=me->query_team();
      count=sizeof(team);
      if(count>3)
{
tell_object(me,"����������������ִ�С�\n" NOR);
	  return "���²������"; //too many people
}      

if(count>1)
{
minexp=ob->query("combat_exp");
	  maxexp=minexp;
      
	  for(i=1;i<count;i++)
      { if(team[i]!=0)
	  { if(team[i]->query("combat_exp")<minexp)
	    minexp=team[i]->query("combat_exp");
		if(team[i]->query("combat_exp")>maxexp)
        maxexp=team[i]->query("combat_exp");
	  }
	  }
	  if ((maxexp-minexp)>2000000)
tell_object(me,"�����е����书���̫�����ˡ�\n" NOR);
      return "���ǵ��书���̫���⡣";//exp too far
}
if (count>1)
{
for(i=1;i<count;i++)
{
team[i]->apply_condition("mjb2_busy",38);	
team[i]->set("quest/quest_type", "���");
team[i]->set("quest/quest", room);	

}	      
}
if (count<1) count=1;
if (!count) count=1;	      

me->apply_condition("mjb2_busy",38);	

me->set("quest/quest_type", "���");
me->set("quest/quest", room);	
me->set("quest/quest_name", "���:"+room);
me->set("task_time", time() + 1080);
me->set("mjb2job","���");
me->set_temp("team_count",count);

	
      //me->start_busy(3);

tell_object(me,"����������,���ֽ�:"+obhs->query("name")+"Ҫ����� ��������"+room+"������\n" NOR);
if (wizardp(me))
tell_object(me,"λ��:"+me->query("quest/location")+"��\n" NOR);


	  return "ȥ�ѵ�������ɡ�";
      	
      }	
      else 
      {
      	room=family_fame[random(39)];
      //��������	
if (room==this_object()->query("mp")) room=family_fame[random(8)];
if (room==this_object()->query("mp")) room=family_fame[random(16)];
if (room==this_object()->query("mp")) room=family_fame[random(22)];
if (room==this_object()->query("mp")) room=family_fame[random(28)];
if (room==this_object()->query("mp")) room=family_fame[random(33)];
if (room==this_object()->query("mp")) room=family_fame[random(39)];



 team=me->query_team();
      count=sizeof(team);
      if(count>3)
{
tell_object(me,"����������������ִ�С�\n" NOR);
	  return "���²������"; //too many people
}      

if(count>1)
{
minexp=ob->query("combat_exp");
	  maxexp=minexp;
      
	  for(i=1;i<count;i++)
      { if(team[i]!=0)
	  { if(team[i]->query("combat_exp")<minexp)
	    minexp=team[i]->query("combat_exp");
		if(team[i]->query("combat_exp")>maxexp)
        maxexp=team[i]->query("combat_exp");
	  }
	  }
	  if ((maxexp-minexp)>2000000)
tell_object(me,"�����е����书���̫�����ˡ�\n" NOR);
      return "���ǵ��书���̫���⡣";//exp too far
}
if (count>1)
{
for(i=1;i<count;i++)
{
team[i]->apply_condition("mjb2_busy",38);	
team[i]->set_temp("questmp", room);	
team[i]->set_temp("questsl", 5);	
}	      
}
if (count<1) count=1;
if (!count) count=1;	      

me->apply_condition("mjb2_busy",38);	

me->set("quest/quest_type", "����");
me->set("quest/quest", room);	
me->set("quest/quest_name", "����:"+room);
me->set("task_time", time() + 1080);
me->set("mjb2job","����");
me->set("quest/questsl", 5);	

tell_object(me,"����Ҫ��"+room+"���������ȥ����(kantou)�˸����˰ɡ�\n" NOR);
if (wizardp(me))
tell_object(me,"�Ը�����:"+room+"��\n" NOR);


	  return "ȥ�ѵ�������ɡ�";

      	
      }	
      
      
      
      
     
}

void unconcious()
{
	this_object()->reincarnate();
	this_object()->set("eff_qi", this_object()->query("max_qi"));
	this_object()->set("qi", this_object()->query("max_qi"));
	this_object()->set("eff_jing", this_object()->query("max_jing"));
	this_object()->set("jing", this_object()->query("max_jing"));
	this_object()->set("jingli", this_object()->query("eff_jingli"));
	this_object()->say( "����ʹ��Ц��˵�������޵в����棡\n");
	this_object()->command("hehe");
}

void die()
{
	this_object()->unconcious();
}        


string ask_gift()
{     object who,ob,me;
      object *team;
	  int i=0,count=0,minexp,maxexp,a,exp,pot;
int ckiller,rn;
      string where;
string file;
string *roomlines;
string location;
int mi,yi,yai,lv,lb,money,score;
    string *ob_list = ({
                "/clone/family/jinkuai",
                "/clone/family/jintiao",
                "/clone/family/xiaoyuanbao",
                "/clone/family/dayuanbao",
                "/clone/family/jinding",
        });
	  who =this_player();
	  me=this_object();
 


if ((int)who->query("mpgx") < 10)
	  return    "������ɹ��׶Ȳ��������ڹ��׶�Ϊ:"+chinese_number(who->query("mpgx"))+"��"; 	  


if (me->is_busy() || who->is_busy())
	  return    "��æ���ء�"; 	  

        if ((int)who->query("age")<=14 && !who->query("zhuanshen"))  
return    "�㻹̫С�����������������(help geren)!"; 	  

//me->start_busy(3);
a=random(3000)+1000;

if (a> 10) 
{	
exp=(int)a/10+10;
pot=(int)exp*2/3+10;
score=188+random(188);
addnl(who,"exp",exp);
	if (who->query("score") < 9000000) who->add("score",score);
	
       message_vision("$n��$N΢΢һЦ�������ɵò�������ָ��������书�ɡ�\n",
                       who, me);
        
        tell_object(who,  "��ľ���������" + chinese_number(exp) + "��Ǳ��������"+chinese_number(pot) +
                         "������������" + chinese_number(score) + "��\n" NOR);

}
        message_vision("$n��$N΢΢һЦ�������ɵò���������"
                       "�ˣ����߽��������и��࿪֧Ӧ�꣬������Щ���ӣ������ȥ�ɡ�\n",
                       who, me);

                ob = new(ob_list[random(sizeof(ob_list))]);
        who->add("mpgx",-10);
        ob->move(who,1);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
                ob = new("/clone/money/gold");
        money=88+random(188);
        if (who->query("combat_exp",1) < 1000000) money=10+random(50);
        if (who->query("combat_exp",1) < 2000000) money=30+random(30);
        if (who->query("combat_exp",1) < 3000000) money=60+random(60);
        if (who->query("combat_exp",1) < 4000000) money=80+random(80);
        tell_object(who, HIY "������" + money +
                        HIY "���ƽ�\n" NOR);

        ob->set_amount(money);
        ob->move(who,1);



if ( (random(8)==0 && (int)who->query("combat_exp",1) > 3000000))
{
lv=0;
lb=random(28)+1;
if (random(2)==0 && lb <=12 ) lb= 12+random(17);
if (random(3)==0 && lb <=12 ) lb= 12+random(17);


if (random(4)==0) lv=100;
if (random(16)==0) lv=200;
if (random(32)==0) lv=300;
if (random(64)==0) lv=400;
if (random(128)==0) lv=500;	
if (random(256)==0) lv=600;
if (random(512)==0) lv=700;
if (random(1024)==0) lv=800;


if (random(2)==0 && lv >=300 ) lv= 300;
if (random(3)==0 && lv >=400 ) lv= 400;

if ((int)who->query("combat_exp",1) < 5000000)
{
	if (lv> 500) lv=500;
}

if ((int)who->query("combat_exp",1) < 10000000)
{
	if (lv> 600) lv=600;
}

if ((int)who->query("combat_exp",1) < 15000000)
{
	if (lv> 700) lv=700;
}

lb=lb+lv;


        message_vision("$n��$N΢΢һЦ�������ɵúã�����"
                       "�ˣ����߽�������Ҫ�м����ֵ�������������Щ����װ���ı�ʯ�������ȥ�ɡ�\n",
                       who, me);
           ob = new("/p/newweapon/weaponobj/jade"+lb);
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
//return    "�����ڵĵȼ�Ϊ:"+lb+"��"; 
}

if (random(5)==0)
{
file = read_file("/clone/medicine/ycgift");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
        message_vision("$n��$N΢΢һЦ�������ɵò���������"
                       "�ˣ����߽��������и���Σ�գ�������Щ��ҩ�������ȥ�ɡ�\n",
                       who, me);
           ob = new(location);
if (ob)
{
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}
}
rn=8;
if ((int)who->query("combat_exp",1) < 2000000)
{
rn=16;
}






if (random(rn)==0)
{
	file = read_file("/clone/medicine/wgift");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
        message_vision("$n��$N΢΢һЦ�������ɵò���������"
                       "�ˣ����߽�������Ҫ�ø���װ����������Щװ���������ȥ�ɡ�\n",
                       who, me);
           ob = new(location);
if (ob)
{
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}


}
mi=1;
if (random(4)==0) mi=2;
if (random(8)==0) mi=3;
if (random(16)==0) mi=4;
if (random(32)==0) mi=5;
if (random(64)==0) mi=6;	
if (random(128)==0) mi=7;
if (random(256)==0) mi=8;
if (random(512)==0) mi=9;
if (random(1024)==0) mi=10;				

yi=1;
if (random(8)==0) yi=2;
if (random(16)==0) yi=3;
if (random(32)==0) yi=4;
if (random(64)==0) yi=5;
if (random(128)==0) yi=6;	

yai=7;
if (random(8)==0) yai=8;
if (random(16)==0) yai=9;
if (random(32)==0) yai=10;
if (random(64)==0) yai=11;
if (random(128)==0) yai=12;	


if ((int)who->query("combat_exp",1) < 10000000)
{
	if (mi> 6) mi=6;
	if (yi> 4) yi=4;
	if (yai> 10) yai=10;
}

if ((int)who->query("combat_exp",1) < 5000000)
{
	if (mi> 5) mi=5;
	if (yi> 3) yi=3;
	if (yai> 9) yai=9;
}


if ((int)who->query("combat_exp",1) < 2000000)
{
	if (mi> 3) mi=3;
	if (yi> 2) yi=2;
	if (yai> 8) yai=8;
}







if (random(3)==0)
{
        message_vision("$n��$N΢΢һЦ�������ɵò���������"
                       "�ˣ����߽�������Ҫ�д���Щ������������Щ������ߵĿ�ʯ�������ȥ�ɡ�\n",
                       who, me);
           ob = new("/p/newweapon/weaponobj/kuangshi"+mi);
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}

if (random(3)==0)
{
        message_vision("$n��$N΢΢һЦ�������ɵò���������"
                       "�ˣ����߽�������Ҫ�д���Щ���ߣ�������Щ���������Ĳ��ϣ������ȥ�ɡ�\n",
                       who, me);
           ob = new("/p/newweapon/weaponobj/buliao"+mi);
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}

if (random(8)==0)
{
        message_vision("$n��$N΢΢һЦ�������ɵò���������"
                       "�ˣ����߽�������Ҫ�д���Щ������������Щ������������ʯ�������ȥ�ɡ�\n",
                       who, me);
           ob = new("/p/newweapon/weaponobj/material"+yi);
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}

if (random(8)==0)
{
        message_vision("$n��$N΢΢һЦ�������ɵò���������"
                       "�ˣ����߽�������Ҫ�д���Щ���ߣ�������Щ������ߵ���ʯ�������ȥ�ɡ�\n",
                       who, me);
           ob = new("/p/newweapon/weaponobj/material"+yai);
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}

if (random(9)==0 && (int)who->query("combat_exp",1) > 1000000)
{
        message_vision("$n��$N΢΢һЦ�������ɵò���������"
                       "�ˣ����߽�������Ҫ������������������Щ�������ı�ʯ�������ȥ�ɡ�\n",
                       who, me);
           ob = new("/clone/gem/gem");
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}


yai=random(100);
 if ((int)who->query("combat_exp",1) > 12000000 && random(3))
{
yai=yai+random(381);
}
else 
 if ((int)who->query("combat_exp",1) > 8500000 && random(3))
{
yai=yai+random(300);
}
else 
 if ((int)who->query("combat_exp",1) > 6500000 && random(3))
{
yai=yai+random(200);
}
else
 if ((int)who->query("combat_exp",1) > 5500000 && random(3))
{
yai=yai+random(100);
}
else if ((int)who->query("combat_exp",1) > 3500000 && random(3))
{
yai=yai+random(50);
}


if (yai>480) yai=479;


if (random(6)==0)
{
if (yai>=100) yai=99;
}

if (random(6)==1)
{
if (yai>=150) yai=149;
}

if (random(6)==2)
{
if (yai>=250) yai=249;
}

if (random(6)==3)
{
if (yai>=350) yai=349;
}

if (random(6)==4)
{
if (yai>=450) yai=449;
}





if (yai>480) yai=479;
if (yai> 400 && random(3)==1) yai=random(400);
if (yai> 300 && random(3)==2) yai=random(300);
if (yai> 200 && random(3)==3) yai=random(200);



if (random(8)==1 && (int)who->query("combat_exp",1) > 2500000)
{
        message_vision("$n��$N΢΢һЦ�������ɵò���������"
                       "�ˣ����߽�������Ҫ��Щ���ֵ������������аѻ�����������������ȥ�ɡ�\n",
                       who, me);
ob = new("/p/item/ritemw/W"+typew[random(9)]+yai);
                ob->set("no_drop",0);
                ob->set("no_get",0);
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}
else if (random(8)==2 && (int)who->query("combat_exp",1) > 2500000)
{
        message_vision("$n��$N΢΢һЦ�������ɵò���������"
                       "�ˣ����߽�������Ҫ��Щ���ֵķ��ߣ������аѻ�����ķ��ߣ������ȥ�ɡ�\n",
                       who, me);
ob = new("/p/item/ritema/A"+typea[random(10)]+yai);
                ob->set("no_drop",0);
                ob->set("no_get",0);
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}

        who->save();
	  

	  return    "�����ڵ�ʦ�Ź��׶�Ϊ:"+chinese_number(who->query("mpgx"))+"��"; 
}
string ask_job1()
{     object guo,ob,me,room2,kill,obhs,mijian,who;
      object *team;
      int i=0,count=0,minexp,maxexp,ttype,rd;
      int wgdj;
      string where;
        string room;
string file;
string *roomlines;
string location,local,fname;
string *dir2;
mapping quest;
	  guo =this_object();
	  ob=this_player();
	  me=this_player();
	  who =this_player();

	  

if (me->is_busy() || guo->is_busy())
	  return    who->query("name")+"��æ���ء�"; 	  

        if ((int)who->query("age")<=14 && !who->query("zhuanshen"))  
return    who->query("name")+"��̫С�����������������(help geren)!"; 	  


if (me->query_condition("menpai_busy2"))
	  return    who->query("name")+"����û������������һ��������"; 	  

if (me->query_temp("nmp1tg"))
	  return    who->query("name")+"���Ȱ������������������"; 	






quest=wheres[random(sizeof(wheres))];
me->set_temp("nmp1tg",quest["weizhi"]);
me->set_temp("nmp1chinese",quest["chinese"]);
me->apply_condition("menpai_busy2",2);
return "��˵��������ϳ���һЩ���� "+who->query("name")+"ȥ"+quest["chinese"]+"ȥ��̽(citan)һЩ�鱨�ɡ�";
}


string ask_job2()
{     object guo,ob,me,room2,kill,obhs,mijian,who;
      object *team;
      int i=0,count=0,minexp,maxexp,ttype,rd;
      int wgdj;
      string where;
        string room;
string file;
string *roomlines;
string location,local,fname;
string *dir2;
mapping quest;
	  guo =this_object();
	  ob=this_player();
	  me=this_player();
	  who=this_player();

	  

if (me->is_busy() || guo->is_busy())
	  return    who->query("name")+"��æ���ء�"; 	  

        if ((int)who->query("age")<=14 && !who->query("zhuanshen"))  
return    who->query("name")+"��̫С�����������������(help geren)!"; 	  

if (me->query_condition("menpai_busy"))
	  return    who->query("name")+"����û������������һ��������"; 	


if (me->query_temp("nmp2tg"))
	  return    who->query("name")+"���Ȱ������������������"; 	



      	room=family_fame[random(39)];
      //��������	
if (room==this_object()->query("mp")) room=family_fame[random(8)];
if (room==this_object()->query("mp")) room=family_fame[random(16)];
if (room==this_object()->query("mp")) room=family_fame[random(22)];
if (room==this_object()->query("mp")) room=family_fame[random(28)];
if (room==this_object()->query("mp")) room=family_fame[random(33)];
if (room==this_object()->query("mp")) room=family_fame[random(39)];



me->apply_condition("menpai_busy",8);
me->set_temp("nmp2tg",room);


tell_object(me,"����Ҫ��"+room+"���������ȥɱ�������е�һ�����˰�(kantou) ��\n" NOR);
return who->query("name")+"ȥ���������Ư��һЩ��";
}

string  zuji(string str)
{   
string output;
      	if (str=="baituo")  

	output="����ɽ��";

if (str=="binghuodao")  

	output="���𵺵�";

if (str=="city")  

	output="���ݵ�";

if (str=="city2" || str=="beijing"  || str=="huanggon"  || str=="huanggong" || str=="beihai")  

	output="�����ǵ�";

if (str=="city4" || str=="changan")   

	output="�����ǵ�";

if (str=="dali")  

	output="�����";

if (str=="emei")  

	output="��üɽ��";

if (str=="foshan")  

	output="��ɽ��";

if (str=="gaibang")  

	output="ؤ���";

if (str=="gaochang")  

	output="�߲��Թ���";

if (str=="guanwai")  

	output="�����";

if (str=="guiyun")  

	output="����ׯ��";

if (str=="gumu")  

	output="��Ĺ�ɵ�";

if (str=="hangzhou")  

	output="���ݵ�";

if (str=="heimuya")  

	output="��ľ�µ�";

if (str=="hengshan")  

	output="��ɽ��";

if (str=="henshan")  

	output="��ɽ��";

if (str=="huanghe")  

	output="�ƺӾ�����";

if (str=="huashan")  

	output="��ɽ��";

if (str=="jinshe")  

	output="����ɽ����";

if (str=="lingjiu")  

	output="���չ���";

if (str=="lingzhou")  

	output="���ݵ�";

if (str=="meizhuang")  

	output="÷ׯ��";

if (str=="mingjiao")  

	output="���̵�";

if (str=="qingcheng")  

	output="���ɽ��";

if (str=="quanzhen")  

	output="ȫ���ɵ�";

if (str=="quanzhou")  

	output="Ȫ�ݵ�";

if (str=="shaolin")  

	output="�����µ�";

if (str=="shenlong")  

	output="��������";

if (str=="songshan")  

	output="��ɽ��";

if (str=="suzhou")  

	output="���ݵ�";

if (str=="taishan")  

	output="̩ɽ��";

if (str=="taohua")  

	output="�һ�����";

if (str=="tianlongsi")  

	output="�����µ�";

if (str=="wanjiegu")  

	output="��ٹȵ�";

if (str=="wudang")  

	output="�䵱ɽ��";

if (str=="xiakedao")  

	output="���͵���";

if (str=="xiangyang")  

	output="�����ǵ�";

if (str=="xiaoyao")  

	output="��ң�ֵ�";

if (str=="xingxiu")  

	output="���޺���";

if (str=="xueshan")  

	output="ѩɽ�µ�";

if (str=="xuedao")  

	output="��ѩɽ��";

if (str=="mr")  

	output="Ľ�����ҵ�";

if (str=="kunlun")  

	output="����ɽ��";

if (str=="tiezhang")  

	output="�����ŵ�";

if (str=="huizhu")  

	output="���岿���";

if (str=="yinju")  

	output="һ�ƴ�ʦ�ӵ�";

if (str=="menggu")  

	output="�ɹŲ�ԭ��";

if (str=="qianjin")  

	output="����ǧ��¥��";

if (str=="lingshedao")  

	output="���ߵ���";

if (str=="ruzhou")  

	output="���ݳǵ�";

if (str=="kunming")  

	output="������";

if (str=="jingzhou")  

	output="���ݵ�";

if (str=="yanjing")  

	output="�ྩ��";

if (str=="lanzhou" || str=="lanzhouchen")  

	output="���ݵ�";

if (str=="jyguan")  

	output="�����Ա������ص�";

if (str=="changcheng")  

	output="�����Ա����ǵ�";

if (str=="fairyland")  

	output="���صĺ�÷ɽׯ";

if (str=="sdxl")  

	output="��ħ�������Ĺ";

if (str=="jqg")  

	output="�����";

if (str=="nio")  

	output="ţ�Ҵ��";

if (str=="feihu")  

	output="�������ص�";

if (str=="wuguan")  

	output="������ݵ�";

if (str=="village")  

	output="��ɽ���";

if (str=="taohuacun")  

	output="�һ����";

if (str=="pingan")  

	output="ƽ���ǵ�";

if (str=="lingxiao")  

	output="�����ǵ�";

if (str=="wudujiao")  

	output="�嶾�̵�";

if (str=="hj")  

	output="��ɽ����ԭ��";
if (str=="dali/yuxu")  

	output="��������۵�";
if (str=="dali/wuliang")  

	output="��������ɽ��";
if (str=="huanghe/yyd")  

	output="�ƺ�������";
if (str=="kaifeng")  

	output="����ǵ�";
if (str=="feitian")  

	output="������������";
if (str=="japan")  

	output="�ձ��񻧵�";
if (str=="tangmen")  

	output="���ŵ�";
if (str=="luoyang")  

	output="�����ǵ�";

if (str=="chengdu" || str=="city3")  

	output="�ɶ���";

if (str=="baihuagu")  

	output="�ٻ��ȵ�";

if (str=="heizhao")  

	output="�ٻ��ȡ����ӵ�";

if (str=="jiaxing")  

	output="���˵�";

if (str=="shiliang")  

	output="�¼�ׯ��";

if (str=="wuyi")  

	output="����ɽ����";

if (str=="yanping")  

	output="��ƽ�ǵ�";
	

if (str=="jiangling")  
{
	output="����ǵ�";
}

if (str=="yueyang")  
{
	output="�����ǵ�";	
}

if (str=="qilian")  
{
	output="����ɽ��";	
}

if (str=="shouxihu")  
{
	output="��������";	
}

if (str=="wuxi")  
{
	output="�����ǵ�";	
}

if (str=="yixing")  
{
	output="���˳ǵ�";	
}
if (str=="taiwan")  
{
	output="̨�������";	
}
if (str=="nanyang")  
{
	output="����������";	
}
if (str=="nanshaolin")  
{
	output="�����ֵ�����";	
}

if (str=="cangzhou")  
{
	output="���ݵ�����";	
}

if (str=="tanggu")  
{
	output="�����ǵ�����";	
}

if (str=="yunhe")  
{
	output="�������˺ӵ�";	
}

if (str=="hainan")  
{
	output="���ϵ���";	
}

if (str=="jindezheng")  
{
	output="�������";	
}

if (str=="yandang")  
{
	output="�㵴ɽ��";	
}

if (str=="jinling")  
{
	output="����ǵ�";	
}

if (str=="sandboy")  
{
	output="����ũ���";	
}

if (str=="huangshan")  
{
	output="��ɽ��";	
}

if (str=="yubifeng")  
{
	output="��ʷ��";	
}

if (str=="quanzhouchen")  
{
	output="Ȫ�ݳ��ڵ�";	
}

if (str=="qingzh")  
{
	output="��ظ�ԭ";	
}

if (str=="changbaishan" || str=="gaoli")  
{
	output="���� ����ɽ��";	
}

if (str=="annan")  
{
	output="���ϸ�����";	
}

if (str=="taiyuan")  
{
	output="̫ԭ������";	
}

if (str=="hefei")  
{
	output="�Ϸʸ�����";	
}

if (str=="jiujiang")  
{
	output="�Ž�������";	
}

if (str=="baling")  
{
	output="���긽����";	
}

if (str=="xinjiang")  
{
	output="�½�������";	
}
if (str=="dingxiang")  
{
	output="���帽����";	
}
if (str=="suiye")  
{
	output="��Ҷ������";	
}


if (str=="mayi")  
{
	output="���ر߽�������";	
}
if (str=="xuzhou")  
{
	output="���ݳǸ�����";	
}
if (str=="jinan")  
{
	output="���ϳǸ�����";	
}
if (str=="guizhou")  
{
	output="�����Ǹ�����";	
}

if (str=="nanchang")  
{
	output="�ϲ��Ǹ�����";	
}


if (str=="changsha")  
{
	output="��ɳ�Ǹ�����";	
}


if (str=="zhongzhou")  
{
	output="���ݳǸ�����";	
}

if (str=="xizang" || str=="zangbei")  
{
	output="���ػ�ر�������";	
}

if (str=="tianshui")  
{
	output="��ˮ�Ǹ�����";	
}

if (str=="datong")  
{
	output="��ͬ��������";	
}
if (str=="ny")  
{
	output="��Զ�Ǹ�����";	
}
if (str=="fengtian")  
{
	output="ʢ���Ǹ�����";	
}

if (str=="yanmen")  
{
	output="���Źظ�����";	
}
if (str=="cloud")  
{
	output="����򸽽���";	
}
if (str=="xueting")  
{
	output="ѩͤ�򸽽���";	
}


return output;
}


void zujinpc(object me,object obj)
{   

	int maxpot;
	int maxexp;
	int maxskill;
	int i;
        if (!me) return;
	maxskill=me->query_skill("force",1);
	maxpot=me->query_temp("maxpot");
	maxexp=me->query("combat_exp",1);
        if (maxskill<200)
        maxskill=200;
        i=me->query_temp("team_count");
        if (!i) i=sizeof(me->query_team());
        if (i==0) i=1;
        if (!i) i=1;


	obj->initlvl(maxskill);
         obj->set("combat_exp",maxexp);
        obj->set("str", me->query("str"));
        obj->set("dex", me->query("dex"));
        obj->set("per", me->query("per"));
        obj->set("qi", me->query("max_qi")*i);
        obj->set("eff_qi", me->query("max_qi")*i);
        obj->set("max_qi", me->query("max_qi")*i);
        obj->set("eff_jing", me->query("max_jing")*i);
        obj->set("max_jing", me->query("max_jing")*i);
        obj->set("jing", me->query("max_jing")*i);
        obj->set("neili", me->query("max_neili")*i);
        obj->set("max_neili", me->query("max_neili")*i);

}

