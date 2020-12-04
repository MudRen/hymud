#include <ansi.h> 
#include <armor.h>

inherit SHIELD;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;37m��Ӱ��[2;37;0m", ({ "diwang shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[36m����֮��[2;37;0m����һ�����ޱȼ�Ӳ��[1;33m����[2;37;0m����[1;33mľ�޻�[2;37;0m�Ƴɣ��ذ˽�������Ǯ��[36m����֮��[2;37;0m��
�ۺ�����[37m������˫[2;37;0m �������ޱȼ�̣�����[32mˮ׼����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[33m��[2;37;0m:[1;33m��ʥ[2;37;0m [1;34m��[2;37;0m:[31m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;31m��˫[2;37;0m ��Ԩ:[36m����[2;37;0m ����:[32m�ֲ�[2;37;0m 
����:[33m�ܸ�[2;37;0m 

�Լ�һ�Ź�׭�֡� [1;32mĽ����[2;37;0m ������һЩ�� [1;32mȭ��[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ebebeb");
		set("ownername", "Ľ����");
		set("value", 16000);
		set("armor_prop/intelligence",40);
		set("armor_prop/strength",40);
		set("armor_prop/karey",40);
		set("armor_prop/percao",40);
		set("armor_prop/dexerity",17);
		set("armor_prop/constitution",32);
    set("armor_prop/dodge", 40);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 49);


    set("armor_prop/armor", 566);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 40);
    set("armor_prop/qi", 40);
    set("armor_prop/jing", 8);
    set("armor_prop/jingli", 32);
    set("armor_prop/damage", 406);

    set("wtypeA",6);
    set("wtypeB",4);
    set("wtypeC",2);
    set("wtypeD",0);
    set("wtypeE",10);
    set("wtypeF",3);
    set("wtypeG",2);
    set("wtypeH",6);
    set("wtypeI",3);
    set("wtypeJ",5);
    set("wtypeK",0);
    set("wtypeL",1);
    
    
                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 12);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";