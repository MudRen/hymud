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
	      set_name("[35m×ÏúQÖ®¶Ü[2;37;0m", ({ "general shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ãæ");
		set("long", @LONG
×ÏúQÖ®¶Ü[2;37;0mÕâÊÇÒ»ÃæÓÉ·Ç³£¼áÓ²µÄ¾«¸Ö¼ÓÉÏ[33mÑÇÂé[2;37;0mÖÆ³É£¬ÖØ¶ş½ïÁãÁ½°ËÇ®µÄ[35m×ÏúQÖ®¶Ü[2;37;0m¡£
×ÛºÏÆÀ¼Û[31mÍêÃÀ¾«ÖÂ[2;37;0m ¿´ÆğÀ´·Ç³£¼á¹Ì£¬¾ßÓĞ[34m²»´í[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[33mºÜ¸ß[2;37;0m [1;35m·ç[2;37;0m:[32m´Ö²Ú[2;37;0m 
[1;34mµç[2;37;0m:[33mºÜ¸ß[2;37;0m [37mÌì[2;37;0m:[32m´Ö²Ú[2;37;0m [40mµØ[2;37;0m:[32m´Ö²Ú[2;37;0m [1;31mÄ§[2;37;0m:[33mºÜ¸ß[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[31m¾«ÖÂ[2;37;0m ÌìÁé:[33mÒ»°ã[2;37;0m ÌìÓî:[33mÒ»°ã[2;37;0m ÇÉÖÆ:[36m²»´í[2;37;0m 
ÌåÁé:[34mÏ¸Ëé[2;37;0m 

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
		set("armor_prop/intelligence",9);
		set("armor_prop/strength",8);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 127);
    set("armor_prop/defense", 21);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",4);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",3);
    set("wtypeG",0);
    set("wtypeH",4);
    set("wtypeI",3);
    set("wtypeJ",3);
    set("wtypeK",0);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "leg",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		


		set("material", "default");
    set("sharpness", 6);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";