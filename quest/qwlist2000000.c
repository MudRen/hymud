//qwlist200000.c

inherit SKILL;
#include <ansi.h>;
mapping *quest=({
(["quest":"��ɫ����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"���ڴ���","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��ݮ","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"���ߵ�","quest_type":"Ѱ","time": 400,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"���ߵ�","quest_type":"Ѱ","time": 400,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��ɫ˿��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�ߵ���","quest_type":"Ѱ","time": 500,"exp_bonus":8,"pot_bonus":3,"score" :20,"quest_city":"����"]),
(["quest":"��Ƥ","quest_type":"Ѱ","time": 500,"exp_bonus":8,"pot_bonus":3,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 500,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�廨Ь","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��ɫ����","quest_type":"Ѱ","time": 500,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"���ڴ���","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"ľ��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�ߵ���","quest_type":"Ѱ","time": 500,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��·����","quest_type":"Ѱ","time": 500,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"pot_bonus":56,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�廨Ь","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"Կ��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),

(["quest":"ţƤ�ƴ�","quest_type":"Ѱ","time": 200,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��Ь","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�廨СЬ","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"���ָ","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��Ƥ","quest_type":"Ѱ","time": 400,"pot_bonus":56,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"������","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�η�Կ��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":20,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"������","quest_type":"Ѱ","time": 400,"exp_bonus":86,"pot_bonus":20,"score" :20,"quest_city":"����"]),
(["quest":"ҩ��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":120,"pot_bonus":9,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��ҩ","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����ƴ�","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"������","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�ۺ����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"���ݴ�","quest_type":"Ѱ","time":400,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":YEL"���־�"NOR,"quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"����"]),
(["quest":YEL"�ټ���"NOR,"quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"����"]),
(["quest":YEL"ǧ����"NOR,"quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"����"]),
(["quest":YEL"����"NOR,"quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"����"]),
(["quest":"ȭ���ܾ�","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"����"]),
(["quest":"�鲼��","quest_type":"Ѱ","time": 200,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"Ƥ����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"ͷ��","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"������Ȧ","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�Ǵ�","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"ţƤ��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"ָ��","quest_type":"Ѱ","time": 400,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 200,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��Ь","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"Ƥѥ","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"Ƥ����","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�ֵ�","quest_type":"Ѱ","time": 400,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��ͨذ��","quest_type":"Ѱ","time": 200,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�β�������","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"������","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��䶹��","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"���㻨��","quest_type":"Ѱ","time": 400,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"���ź��","quest_type":"Ѱ","time": 400,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"������","quest_type":"Ѱ","time": 200,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�����Ҳ�","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����ë��","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����ϸë��","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��ɽ����","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"������Ƭ","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��ɽë��","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��������","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"���۷�","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":HIW"��ʯͷ"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":GRN"����֦"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),

(["quest":"���չ���","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"ؤ��"]),
(["quest":"���","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"ؤ��"]),

(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"Ƥ����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"������","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
	
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�ֲ���","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),

(["quest":"��ɫ����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),

(["quest":"��Ƥ","quest_type":"Ѱ","time": 400,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"����"]),

(["quest":"���Ķ�ȹ","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"���ƹ���","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"���¾���","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"խ�̰�","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��������","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 700,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"ë̺","quest_type":"Ѱ","time": 700,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��ɴ�������ȹ","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"̨�Ķ�ȹ","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"Ͳȹ","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"̨��ͷ��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"���ĳ�ȹ","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"���Ĵ���","quest_type":"Ѱ","time": 400,"pot_bonus":56,"pot_bonus":26,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�׳���","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"Բ��С��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��ɴ��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":HIR"ɽ�軨"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":HIG"Ҷ����"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":HIR"��������"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":HIY"������"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":HIB"��"HIW"����"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":HIR"��ױ"HIW"�ع�"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":HIW"ץ��"HIG"��"NOR"��"HIR"��"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":HIW"��"HIG"��"HIR"��"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":HIR"ʮ��ѧʿ"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":HIG"ʮ��̫��"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":HIB"���ɹ���"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":HIR"����Ů"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":MAG"��"WHT"����"HIR"��"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":HIR"��"WHT"��"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":HIG"�˱�ױ"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":HIW"����"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":WHT"������"NOR,"quest_type":"Ѱ","time":500,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":HIW"���߸�"NOR,"quest_type":"Ѱ","time":500,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),

(["quest":"�ܵ���","quest_type":"Ѱ","time": 400,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"����"]),

(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����ׯ"]),

(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"�ྩ"]),

(["quest":"�ײ�����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"������","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
	
(["quest":"������ǹ","quest_type":"Ѱ","time": 300,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"̨��"]),
	
(["quest":"����","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��ߺڲ�����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�಼ɮ��","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�Ҳ��������","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�಼�������","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��ü��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�ײ��ڱ�����","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�಼ɮ��","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"������","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�Ʋ�����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"��������","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����Ƭ","quest_type":"Ѱ","time":600,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"����"]),
(["quest":"������","quest_type":"Ѱ","time":600,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"����"]),
(["quest":YEL"�׽"NOR,"quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"����"]),
	
(["quest":"�ٻ����߸�","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"������"]),
(["quest":"������","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"������"]),
(["quest":"���ߵ�","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"������"]),
(["quest":"ˮ����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"������"]),
(["quest":"���ߵ�","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"������"]),
(["quest":"�ۻ�","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"������"]),
(["quest":"������ʽ�ַ�","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"������"]),

(["quest":"�಼��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"�һ���"]),
(["quest":"���ɲ�","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"�һ���"]),
(["quest":"�ֲ���","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"�һ���"]),
(["quest":"�һ���","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"�һ���"]),
(["quest":"�������" ,"quest_type":"Ѱ","time": 700,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"�һ���"]),
(["quest":"����","quest_type":"Ѱ","time": 800,"exp_bonus":8,"pot_bonus":20,"score" :20,"quest_city":"�һ���"]),
(["quest":"��ľ��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"�һ���"]),
(["quest":"������","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"�һ���"]),
(["quest":"����","quest_type":"Ѱ","time": 600,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"�һ���"]),
(["quest":"����ɨҶ�ȷ�","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"�һ���"]),
(["quest":HIY"���׾�����ƪ��"NOR,"quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"�һ���"]),
(["quest":HIY"���׾�˵��ƪ��"NOR,"quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"�һ���"]),
(["quest":HIY"���׾�����ƪ��"NOR,"quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"�һ���"]),
(["quest":HIY"���׾�ϵ��ƪ��"NOR,"quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"�һ���"]),
	
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"������"]),
(["quest":"��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"������"]),

(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���͵�"]),

(["quest":"ʯ��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),

(["quest":"С����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"��ң"]),
(["quest":"�׷�","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"��ң"]),
(["quest":"�׽��ѧƪ","quest_type":"Ѱ","time":600,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"��ң"]),

(["quest":"�ɺ�ҩ","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���޺�"]),
(["quest":"ɳ���","quest_type":"Ѱ","time": 500,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���޺�"]),
(["quest":"���","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���޺�"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���޺�"]),
(["quest":"��˹����","quest_type":"Ѱ","time": 500,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���޺�"]),
(["quest":"������","quest_type":"Ѱ","time": 500,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���޺�"]),
(["quest":"Сë¿","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���޺�"]),
(["quest":"���ܹ�","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���޺�"]),
(["quest":"������","quest_type":"Ѱ","time": 500,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���޺�"]),
(["quest":"���̾ƺ�","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���޺�"]),
(["quest":"��","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���޺�"]),
(["quest":"ͭ��","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���޺�"]),
(["quest":"ͭ��","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���޺�"]),
(["quest":"ͭ��","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���޺�"]),
(["quest":"�����޶������ϲ᡽��","quest_type":"Ѱ","time":600,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"���޺�"]),
(["quest":"�����޶������²᡽��","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"���޺�"]),
(["quest":HIM"������"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"���޺�"]),
(["quest":HIG"���ĵ�"NOR,"quest_type":"Ѱ","time":300,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"���޺�"]),
(["quest":HIG"���«"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"���޺�"]),
(["quest":HIG"������"NOR,"quest_type":"Ѱ","time":400,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"���޺�"]),
	
(["quest":"�������䵶","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"��ɽ"]),
(["quest":"ά����峤��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"��ɽ"]),

(["quest":"������","quest_type":"Ѱ","time": 500,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"ѩɽ"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"ѩɽ"]),
(["quest":"ľ��","quest_type":"Ѱ","time": 500,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"ѩɽ"]),
(["quest":"ţƤ��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"ѩɽ"]),
(["quest":"������","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"ѩɽ"]),
	
(["quest":"�಼����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":RED"������"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":HIG"���̽�"NOR,"quest_type":"Ѱ","time":500,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":GRN"��ƿ"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":" ����"]),
(["quest":HIY"�ٹ��Ͱ�"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":" ����"]),
(["quest":YEL"�л�ͯ��"NOR,"quest_type":"Ѱ","time":400,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":" ����"]),
(["quest":RED"��������"NOR,"quest_type":"Ѱ","time":400,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":" ����"]),
(["quest":HIR"��������"NOR,"quest_type":"Ѱ","time":400,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":" ����"]),
(["quest":GRN"��ƿ"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":" ����"]),
(["quest":RED"����Ϻ��"NOR,"quest_type":"Ѱ","time":400,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":" ����"]),

(["quest":"�����ⵣ","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����ׯ"]),
(["quest":"�˳�","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����ׯ"]),
(["quest":"�⵶","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����ׯ"]),
(["quest":"�Žڱ�","quest_type":"Ѱ","time": 400,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"����ׯ"]),
(["quest":"�̵�","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����ׯ"]),
(["quest":"��ֽ����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����ׯ"]),
(["quest":HIG"�಼��"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����ׯ"]),

 (["quest":"����Կ��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"������Ƥ��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"������","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�ϳ���","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�Ͻ�","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
	
(["quest":"ɥ�Ÿ�","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"�ƺӾ���"]),
(["quest":"�𲼳���","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"�ƺӾ���"]),
(["quest":"��ˮ��","quest_type":"Ѱ","time": 600,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"�ƺӾ���"]),
(["quest":"���ɲ�","quest_type":"Ѱ","time": 600,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"�ƺӾ���"]),
(["quest":"��ͷ","quest_type":"Ѱ","time": 400,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"�ƺӾ���"]),
(["quest":"ҹ��ˮ��","quest_type":"Ѱ","time": 400,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"�ƺӾ���"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"�ƺӾ���"]),
(["quest":HIC"����ʯ"NOR,"quest_type":"Ѱ","time":400,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"�ƺӾ���"]),

(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���չ�"]),
(["quest":"��ѩ����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���չ�"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���չ�"]),
(["quest":"��÷��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���չ�"]),
(["quest":"��ɽ��÷�ַ�ͼ�Ͼ�","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"���չ�"]),
(["quest":"��ɽ��÷�ַ�ͼ�¾�","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"���չ�"]),
(["quest":"��ɽ�����Ʒ�ͼ�ϲ�","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"���չ�"]),
(["quest":"��ɽ�����Ʒ�ͼ�²�","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"���չ�"]),
(["quest":"�����潣����","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"���չ�"]),

(["quest":"���¾����Ͼ���","quest_type":"Ѱ","time":600,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"�䵱"]),
(["quest":"���¾����¾���","quest_type":"Ѱ","time":600,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"�䵱"]),
(["quest":"���¾�","quest_type":"Ѱ","time":600,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"�䵱"]),
(["quest":"̫��ʮ����","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"�䵱"]),
(["quest":"���¾�����һ�¡�","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"�䵱"]),
(["quest":"���¾�����ʮ���¡�","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"�䵱"]),
(["quest":"���¾�����ʮ���¡�","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"�䵱"]),
(["quest":"���¾�����ʮ���¡�","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"�䵱"]),
(["quest":"���¾����ڶ��¡�","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"�䵱"]),
(["quest":"���¾����ڰ��¡�","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"�䵱"]),
	
(["quest":RED"ӣ�һ���"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"Ľ��ɽׯ"]),
(["quest":HIG"��Ҷ������"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"Ľ��ɽׯ"]),
(["quest":WHT"���Ϻ��"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"Ľ��ɽׯ"]),

(["quest":RED"����ǽ"NOR,"quest_type":"Ѱ","time":500,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
	
(["quest":HIR"��籰�"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"�ʹ�"]),

(["quest":HIC"���ӽ�"NOR,"quest_type":"Ѱ","time":500,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"�����"]),
		
(["quest":HIY"����ͭ��"NOR,"quest_type":"Ѱ","time":500,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
(["quest":HIC"������"NOR,"quest_type":"Ѱ","time":500,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"����"]),
	
(["quest":"�˵�","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"��ɽ"]),
(["quest":HIW"�׺ϻ�"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"��ɽ"]),
(["quest":HIR"ɯ须�"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"��ɽ"]),
(["quest":HIB"ޥ����"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"��ɽ"]),
(["quest":HIW"ʯ��"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"��ɽ"]),
(["quest":GRN"С��֦"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"��ɽ"]),
		
(["quest":WHT"��ɫ����"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"ȫ��"]),
(["quest":HIG"��ɫ����"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"ȫ��"]),
(["quest":WHT"��ɫ����"NOR,"quest_type":"Ѱ","time":200,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"ȫ��"]),
(["quest":HIB"�ڹ��"NOR,"quest_type":"Ѱ","time":400,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"ȫ��"]),
(["quest":YEL"����"NOR,"quest_type":"Ѱ","time":400,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"ȫ��"]),
(["quest":HIW"ûҩ"NOR,"quest_type":"Ѱ","time":400,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"ȫ��"]),
(["quest":HIY"����"NOR,"quest_type":"Ѱ","time":400,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"ȫ��"]),
(["quest":HIR"�ܵ�"NOR,"quest_type":"Ѱ","time":400,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"ȫ��"]),
(["quest":RED"Ѫ��"NOR,"quest_type":"Ѱ","time":400,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"ȫ��"]),
	
(["quest":HIY"��ɫ����"NOR,"quest_type":"Ѱ","time":400,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"ѩɽ"]),
(["quest":HIW"����"NOR,"quest_type":"Ѱ","time":400,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"ѩɽ"]),
(["quest":"�����ľ�","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"ѩɽ"]),

(["quest":"����������","quest_type":"Ѱ","time":500,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"��ľ��"]),
(["quest":"�׻�������","quest_type":"Ѱ","time":500,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"��ľ��"]),
(["quest":"����������","quest_type":"Ѱ","time":500,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"��ľ��"]),
(["quest":"����������","quest_type":"Ѱ","time":500,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"��ľ��"]),

(["quest":"��а����","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"��ɽ"]),
(["quest":"��ɽ����","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"��ɽ"]),
(["quest":HIG"��ˮ��"NOR,"quest_type":"Ѱ","time":500,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"��ɽ"]),
(["quest":CYN"��Ȫ��"NOR,"quest_type":"Ѱ","time":400,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"��ɽ"]),
(["quest":HIR"������"NOR,"quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"��ɽ"]),
(["quest":MAG"��ϼ��ܸ"NOR,"quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"��ɽ"]),

(["quest":"Ⱥ����ͼ","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"÷ׯ"]),
(["quest":"���Ǻ컨","quest_type":"Ѱ","time":600,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"÷ׯ"]),
(["quest":"�Ϻ���ľ","quest_type":"Ѱ","time":600,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"÷ׯ"]),
(["quest":HIG"������"NOR,"quest_type":"Ѱ","time":400,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"÷ׯ"]),
(["quest":HIR"����Կ��"NOR,"quest_type":"Ѱ","time":400,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"÷ׯ"]),
(["quest":BLK"��ľ��"NOR,"quest_type":"Ѱ","time":500,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"÷ׯ"]),
(["quest":"��ɫ����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"÷ׯ"]),
(["quest":"�����йٱ�","quest_type":"Ѱ","time": 600,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"÷ׯ"]),
(["quest":"��÷����","quest_type":"Ѱ","time": 600,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"÷ׯ"]),
(["quest":"���","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"÷ׯ"]),
(["quest":"���Ǻ컨","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"÷ׯ"]),
(["quest":"�Ϻ���ľ","quest_type":"Ѱ","time": 600,"exp_bonus":86,"pot_bonus":40,"score" :20,"quest_city":"÷ׯ"]),
(["quest":"Ѫ����","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"÷ׯ"]),
		
(["quest":"��Ů����","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"��Ĺ"]),
(["quest":HIM"��Ů�ľ��ϲ�"NOR,"quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"��Ĺ"]),
(["quest":HIM"��Ů�ľ��²�"NOR,"quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"��Ĺ"]),
(["quest":HIC"��Ů��"NOR,"quest_type":"Ѱ","time":500,"exp_bonus":110,"pot_bonus":54,"score":5,"quest_city":"��Ĺ"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"��Ĺ"]),

(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":26,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"�����޷�","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"����"]),
(["quest":"��������","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"����"]),
(["quest":"��������","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"����"]),
(["quest":"������","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"����"]),
(["quest":"���������Ͼ���","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"����"]),
(["quest":"���������¾���","quest_type":"Ѱ","time":800,"exp_bonus":240,"pot_bonus":50,"score":5,"quest_city":"����"]),
(["quest":"��Ҷ","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),
(["quest":"����","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"����"]),

(["quest":"ĥ��ʯ","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"��ˮ"]),
(["quest":"ͭԿ��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"��ˮ"]),
(["quest":"�춵��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"��ˮ"]),
	
(["quest":"��ɫ��ϸ��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"�˹�����"]),
(["quest":"��ɫ��ϸ��","quest_type":"Ѱ","time": 400,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"�˹�����"]),

(["quest":"���Ǻ�«","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���"]),
(["quest":"����","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���"]),
(["quest":"ˮ��","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"���"]),
	
(["quest":"����","quest_type":"Ѱ","time": 300,"exp_bonus":80,"pot_bonus":40,"score" :20,"quest_city":"��Զ"]),
	
(["quest":"����","quest_type":"Ѱ","time": 500,"exp_bonus":100,"pot_bonus":50,"score" :20,"quest_city":"��ͤ"]),

(["quest":"������","quest_type":"Ѱ","time": 500,"exp_bonus":100,"pot_bonus":50,"score" :20,"quest_city":"ѩͤ��"]),
(["quest":"������","quest_type":"Ѱ","time": 500,"exp_bonus":100,"pot_bonus":50,"score" :20,"quest_city":"ѩͤ��"]),
	
(["quest":"ֽǮ","quest_type":"Ѱ","time": 500,"exp_bonus":100,"pot_bonus":50,"score" :20,"quest_city":"�����"]),
(["quest":"ֽ��","quest_type":"Ѱ","time": 500,"exp_bonus":100,"pot_bonus":50,"score" :20,"quest_city":"�����"]),
});

mapping query_quest()
{
return quest[random(sizeof(quest))];
}


