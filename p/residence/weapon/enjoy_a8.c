#include <ansi.h> 
#include <armor.h>

inherit HANDS;

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
	      set_name("[1;31mī��[2;37;0m", ({ "lianyu hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;31m��ʮ�������еأ������гǣ�������ǣ���С��ħ�������������ڴ��ֻ�������ν֮����������
[2;37;0m����һ�����ޱȼ�Ӳ��[37m����[2;37;0m����[37m���˿[2;37;0m�Ƴɣ�������һ����Ǯ��[1;31m����֮����[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȼ�̣�����[34m����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;31mħ[2;37;0m:[35m��׼[2;37;0m [32mˮ[2;37;0m:[1;31m��˫[2;37;0m [31m��[2;37;0m:[1;34m����[2;37;0m [33m��[2;37;0m:[1;34m����[2;37;0m [1;35m��[2;37;0m:[1;31m��Ԫ[2;37;0m 

���滹����һЩ���֣�
��Ӳ:[1;31m����[2;37;0m ����:[32m�ֲ�[2;37;0m ����:[33m�ܸ�[2;37;0m 
��ʯ:[31m����[2;37;0m ��ʯ:[31m����[2;37;0m ����:[35m��׼[2;37;0m ����:[1;36m����[2;37;0m ����:[32m�ֲ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m������[2;37;0m ������һЩ�� [1;32m�м�[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "enjoy");
		set("ownername", "������");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",32);
		set("armor_prop/karey",56);
		set("armor_prop/percao",32);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",64);
    set("armor_prop/dodge", 65);
    set("armor_prop/parry", 66);
    set("armor_prop/attack", 32);


    set("armor_prop/armor", 1353);
    set("armor_prop/defense", 64);
    
    set("armor_prop/neili", 57);
    set("armor_prop/qi", 72);
    set("armor_prop/jing", 64);
    set("armor_prop/jingli", 56);
    set("armor_prop/damage", 1693);

    set("wtypeA",7);
    set("wtypeB",8);
    set("wtypeC",12);
    set("wtypeD",8);
    set("wtypeE",8);
    set("wtypeF",13);
    set("wtypeG",4);
    set("wtypeH",6);
    set("wtypeI",8);
    set("wtypeJ",7);
    set("wtypeK",8);
    set("wtypeL",8);
    
    
                set("skill", ([
                        "name": "parry",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 20);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";