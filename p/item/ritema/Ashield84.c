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
	      set_name("[1;32mÀ«Ö®¶Ü[2;37;0m", ({ "bad shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ãæ");
		set("long", @LONG
À«Ö®¶Ü[2;37;0mÕâÊÇÒ»ÃæÓÉÊ®·Ö¼áÓ²µÄ¾«¸Ö¼ÓÉÏ[1;37mÃÞ»¨[2;37;0mÖÆ³É£¬ÖØÒ»½ï¾ÅÁ½ÎåÇ®µÄ[1;32mÀ«Ö®¶Ü[2;37;0m¡£
×ÛºÏÆÀ¼Û[32m¾«ÖÂÏ¸ÃÀ[2;37;0m ¿´ÆðÀ´Ê®·Ö¼á¹Ì£¬¾ßÓÐ[36m²»Ð¡[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[33mÍÁ[2;37;0m:[32m´Ö²Ú[2;37;0m [1;35m·ç[2;37;0m:[33mºÜ¸ß[2;37;0m 
[1;34mµç[2;37;0m:[36m²»´í[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ð©·û×Ö£º
¼áÓ²:[32m´Ö²Ú[2;37;0m ÌìÁé:[32m¼«²î[2;37;0m ÇÉÖÆ:[32m¼«²î[2;37;0m 
ÌåÁé:[33mÒ»°ã[2;37;0m °×Ê¯:[33mÒ»°ã[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 2000);
		set("armor_prop/intelligence",3);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 6);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 114);
    set("armor_prop/defense", 8);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",3);
    set("wtypeF",4);
    set("wtypeG",0);
    set("wtypeH",1);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "cuff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		


		set("material", "default");
    set("sharpness", 3);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";