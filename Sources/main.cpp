#include<chrono>
#include<cstdint>
#include<cstdlib>
#include<ios>
#include<iostream>
#include<limits>
#include<random>
#include<utility>
#include<vector>
#include"tree_vector.h"

void default_construtor_benchmark()
{
    std::cout<<"Starting default constructor benchmark...\n";

    std::cout<<"Default constructing std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    const std::vector<std::uintmax_t> system_vector;

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Default construction for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Default constructing tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    const tree_vector<std::uintmax_t> system_tree_vector;

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Default construction for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void copy_constructor_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting copy constructor benchmark...\n";

    std::cout<<"Constructing std::vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    const std::vector<std::uintmax_t> source_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));

    std::cout<<"Copy constructing std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    const std::vector<std::uintmax_t> system_vector(source_vector);

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Copy construction for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Constructing tree_vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    const tree_vector<std::uintmax_t> source_tree_vector(static_cast<std::size_t>(source_value_count));

    std::cout<<"Copy constructing tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    const tree_vector<std::uintmax_t> system_tree_vector(source_tree_vector);

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Copy construction for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void move_constructor_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting move constructor benchmark...\n";

    std::cout<<"Constructing std::vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    std::vector<std::uintmax_t> source_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));

    std::cout<<"Move constructing std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    const std::vector<std::uintmax_t> system_vector(std::move(source_vector));

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Move construction for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Constructing tree_vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    tree_vector<std::uintmax_t> source_tree_vector(static_cast<std::size_t>(source_value_count));

    std::cout<<"Move constructing tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    const tree_vector<std::uintmax_t> system_tree_vector(std::move(source_tree_vector));

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Move construction for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void value_count_constructor_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting value count constructor benchmark...\n";

    std::cout<<"Value count constructing std::vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    const std::vector<std::uintmax_t> system_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count),
                                                    std::numeric_limits<std::uintmax_t>::max());

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Value count construction for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Value count constructing tree_vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    start_time_point=std::chrono::steady_clock::now();

    const tree_vector<std::uintmax_t> system_tree_vector(static_cast<std::size_t>(source_value_count),
                                                         std::numeric_limits<std::uintmax_t>::max());

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Value count construction for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void iterator_constructor_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting iterator constructor benchmark...\n";

    std::cout<<"Constructing std::vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    const std::vector<std::uintmax_t> source_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));

    std::cout<<"Iterator constructing std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    const std::vector<std::uintmax_t> system_vector(source_vector.cbegin(),
                                                    source_vector.cend());

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Iterator construction for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Iterator constructing tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    const tree_vector<std::uintmax_t> system_tree_vector(source_vector.cbegin(),
                                                         source_vector.cend());

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Iterator construction for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void initializer_list_constructor_benchmark()
{
    std::cout<<"Starting initializer list constructor benchmark...\n";

    std::cout<<"Initializer list constructing std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    const std::vector<std::uintmax_t> system_vector
    {
        std::uintmax_t(),
        static_cast<std::uintmax_t>(1),
        static_cast<std::uintmax_t>(2),
        static_cast<std::uintmax_t>(3),
        static_cast<std::uintmax_t>(4),
        static_cast<std::uintmax_t>(5),
        static_cast<std::uintmax_t>(6),
        static_cast<std::uintmax_t>(7),
        static_cast<std::uintmax_t>(8),
        static_cast<std::uintmax_t>(9)
    };

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Initializer list construction for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Initializer list constructing tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    const tree_vector<std::uintmax_t> system_tree_vector
    {
        std::uintmax_t(),
        static_cast<std::uintmax_t>(1),
        static_cast<std::uintmax_t>(2),
        static_cast<std::uintmax_t>(3),
        static_cast<std::uintmax_t>(4),
        static_cast<std::uintmax_t>(5),
        static_cast<std::uintmax_t>(6),
        static_cast<std::uintmax_t>(7),
        static_cast<std::uintmax_t>(8),
        static_cast<std::uintmax_t>(9)
    };

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Initializer list construction for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void copy_assignment_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting copy assignment benchmark...\n";

    std::cout<<"Constructing std::vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    const std::vector<std::uintmax_t> source_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));

    std::vector<std::uintmax_t> system_vector;
    std::cout<<"Copy assigning std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    system_vector=source_vector;

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Copy assignment for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Constructing tree_vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    const tree_vector<std::uintmax_t> source_tree_vector(static_cast<std::size_t>(source_value_count));

    tree_vector<std::uintmax_t> system_tree_vector;
    std::cout<<"Copy assigning tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    system_tree_vector=source_tree_vector;

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Copy assignment for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void move_assignment_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting move assignment benchmark...\n";

    std::cout<<"Constructing std::vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    std::vector<std::uintmax_t> source_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));

    std::vector<std::uintmax_t> system_vector;
    std::cout<<"Move assigning std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    system_vector=std::move(source_vector);

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Move assignment for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Constructing tree_vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    tree_vector<std::uintmax_t> source_tree_vector(static_cast<std::size_t>(source_value_count));

    tree_vector<std::uintmax_t> system_tree_vector;
    std::cout<<"Move assigning tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    system_tree_vector=std::move(source_tree_vector);

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Move assignment for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void initializer_list_assignment_benchmark()
{
    std::cout<<"Starting initializer list assignment benchmark...\n";

    std::vector<std::uintmax_t> system_vector;
    std::cout<<"Initializer list assigning std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    system_vector=
    {
        std::uintmax_t(),
        static_cast<std::uintmax_t>(1),
        static_cast<std::uintmax_t>(2),
        static_cast<std::uintmax_t>(3),
        static_cast<std::uintmax_t>(4),
        static_cast<std::uintmax_t>(5),
        static_cast<std::uintmax_t>(6),
        static_cast<std::uintmax_t>(7),
        static_cast<std::uintmax_t>(8),
        static_cast<std::uintmax_t>(9)
    };

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Initializer list assignment for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    tree_vector<std::uintmax_t> system_tree_vector;
    std::cout<<"Initializer list assigning tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    system_tree_vector=
    {
        std::uintmax_t(),
        static_cast<std::uintmax_t>(1),
        static_cast<std::uintmax_t>(2),
        static_cast<std::uintmax_t>(3),
        static_cast<std::uintmax_t>(4),
        static_cast<std::uintmax_t>(5),
        static_cast<std::uintmax_t>(6),
        static_cast<std::uintmax_t>(7),
        static_cast<std::uintmax_t>(8),
        static_cast<std::uintmax_t>(9)
    };

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Initializer list assignment for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void value_count_assignment_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting value count assignment benchmark...\n";

    std::cout<<"Value count assigning std::vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    std::vector<std::uintmax_t> system_vector;
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    system_vector.assign(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count),
                         std::numeric_limits<std::uintmax_t>::max());

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Value count assignment for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Value count assigning tree_vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    tree_vector<std::uintmax_t> system_tree_vector;
    start_time_point=std::chrono::steady_clock::now();

    system_tree_vector.assign(static_cast<std::size_t>(source_value_count),
                              std::numeric_limits<std::uintmax_t>::max());

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Value count assignment for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void iterator_assignment_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting iterator assignment benchmark...\n";

    std::cout<<"Constructing std::vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    const std::vector<std::uintmax_t> source_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));

    std::vector<std::uintmax_t> system_vector;
    std::cout<<"Iterator assigning std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    system_vector.assign(source_vector.cbegin(),
                         source_vector.cend());

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Iterator assignment for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    tree_vector<std::uintmax_t> system_tree_vector;
    std::cout<<"Iterator assigning tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    system_tree_vector.assign(source_vector.cbegin(),
                              source_vector.cend());

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Iterator assignment for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void bracket_find_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting bracket find benchmark...\n";

    std::cout<<"Constructing std::vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    std::vector<std::uintmax_t> system_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));

    std::cout<<"Bracket finding std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    for(std::vector<std::uintmax_t>::size_type index{};
        index<system_vector.size();
        ++index)
    {
        system_vector[index]=(static_cast<std::uintmax_t>(index)
                              <<static_cast<std::uintmax_t>(1));
    }

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Bracket find for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Constructing tree_vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    tree_vector<std::uintmax_t> system_tree_vector(static_cast<std::size_t>(source_value_count));

    std::cout<<"Bracket finding tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    for(std::size_t index{};
        index<system_tree_vector.size();
        ++index)
    {
        system_tree_vector[index]=(static_cast<std::uintmax_t>(index)
                                   <<static_cast<std::uintmax_t>(1));
    }

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Bracket find for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void at_find_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting at find benchmark...\n";

    std::cout<<"Constructing std::vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    std::vector<std::uintmax_t> system_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));

    std::cout<<"At finding std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    for(std::vector<std::uintmax_t>::size_type index{};
        index<system_vector.size();
        ++index)
    {
        system_vector.at(index)=(static_cast<std::uintmax_t>(index)
                                 <<static_cast<std::uintmax_t>(1));
    }

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"At find for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Constructing tree_vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    tree_vector<std::uintmax_t> system_tree_vector(static_cast<std::size_t>(source_value_count));

    std::cout<<"At finding tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    for(std::size_t index{};
        index<system_tree_vector.size();
        ++index)
    {
        system_tree_vector.at(index)=(static_cast<std::uintmax_t>(index)
                                      <<static_cast<std::uintmax_t>(1));
    }

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"At find for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void iterator_traverse_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting iterator traverse benchmark...\n";

    std::cout<<"Constructing std::vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    std::vector<std::uintmax_t> system_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));

    std::cout<<"Iterator traversing std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    for(std::uintmax_t& system_value:system_vector)
    {
        system_value<<=static_cast<std::uintmax_t>(1);
    }

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Iterator traversal for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Constructing tree_vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    tree_vector<std::uintmax_t> system_tree_vector(static_cast<std::size_t>(source_value_count));

    std::cout<<"Iterator traversing tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    for(std::uintmax_t& system_value:system_tree_vector)
    {
        system_value<<=static_cast<std::uintmax_t>(1);
    }

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Iterator traversal for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void reverse_iterator_traverse_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting reverse iterator traverse benchmark...\n";

    std::cout<<"Constructing std::vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    std::vector<std::uintmax_t> system_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));

    std::cout<<"Reverse iterator traversing std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    for(std::vector<std::uintmax_t>::reverse_iterator iterator(system_vector.rbegin());
        iterator!=system_vector.rend();
        ++iterator)
    {
        (*iterator)<<=static_cast<std::uintmax_t>(1);
    }

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Reverse iterator traversal for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Constructing tree_vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    tree_vector<std::uintmax_t> system_tree_vector(static_cast<std::size_t>(source_value_count));

    std::cout<<"Reverse iterator traversing tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    for(tree_vector<std::uintmax_t>::reverse_iterator iterator(system_tree_vector.rbegin());
        iterator!=system_tree_vector.rend();
        ++iterator)
    {
        (*iterator)<<=static_cast<std::uintmax_t>(1);
    }

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Reverse iterator traversal for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void push_back_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting push back benchmark...\n";

    std::cout<<"Pushing back std::vector<std::uintmax_t>()...\n";
    std::vector<std::uintmax_t> system_vector;

    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    for(std::uintmax_t index{};
        index<source_value_count;
        ++index)
    {
        system_vector.push_back(index);
    }

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Push back for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Pushing back tree_vector<std::uintmax_t>()...\n";
    tree_vector<std::uintmax_t> system_tree_vector;

    start_time_point=std::chrono::steady_clock::now();

    for(std::uintmax_t index{};
        index<source_value_count;
        ++index)
    {
        system_tree_vector.push_back(index);
    }

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Push back for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void emplace_back_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting emplace back benchmark...\n";

    std::cout<<"Emplacing back std::vector<std::uintmax_t>()...\n";
    std::vector<std::uintmax_t> system_vector;

    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    for(std::uintmax_t index{};
        index<source_value_count;
        ++index)
    {
        system_vector.emplace_back(index);
    }

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Emplace back for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Emplacing back tree_vector<std::uintmax_t>()...\n";
    tree_vector<std::uintmax_t> system_tree_vector;

    start_time_point=std::chrono::steady_clock::now();

    for(std::uintmax_t index{};
        index<source_value_count;
        ++index)
    {
        system_tree_vector.emplace_back(index);
    }

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Emplace back for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void insert_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting insert benchmark...\n";

    std::random_device device;
    std::default_random_engine engine(device());
    std::uniform_int_distribution<std::size_t> distribution;

    std::cout<<"Inserting std::vector<std::uintmax_t>()...\n";
    std::vector<std::uintmax_t> system_vector;

    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    for(std::uintmax_t index{};
        index<source_value_count;
        ++index)
    {
        distribution=std::uniform_int_distribution<std::size_t>(std::size_t(),
                                                                system_vector.empty()
                                                                ?std::size_t()
                                                                :static_cast<std::size_t>(system_vector.size())
                                                                -static_cast<std::size_t>(1));
        system_vector.insert(system_vector.begin()
                             +static_cast<std::vector<std::uintmax_t>::difference_type>(distribution(engine)),
                             std::numeric_limits<std::uintmax_t>::max());
    }

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Insertion for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Inserting tree_vector<std::uintmax_t>()...\n";
    tree_vector<std::uintmax_t> system_tree_vector;

    start_time_point=std::chrono::steady_clock::now();

    for(std::uintmax_t index{};
        index<source_value_count;
        ++index)
    {
        distribution=std::uniform_int_distribution<std::size_t>(std::size_t(),
                                                                system_tree_vector.empty()
                                                                ?std::size_t()
                                                                :static_cast<std::size_t>(system_tree_vector.size())
                                                                -static_cast<std::size_t>(1));
        system_tree_vector.insert(distribution(engine),
                                  std::numeric_limits<std::uintmax_t>::max());
    }

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Insertion for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void emplace_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting emplace benchmark...\n";

    std::random_device device;
    std::default_random_engine engine(device());
    std::uniform_int_distribution<std::size_t> distribution;

    std::cout<<"Emplacing std::vector<std::uintmax_t>()...\n";
    std::vector<std::uintmax_t> system_vector;

    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    for(std::uintmax_t index{};
        index<source_value_count;
        ++index)
    {
        distribution=std::uniform_int_distribution<std::size_t>(std::size_t(),
                                                                system_vector.empty()
                                                                ?std::size_t()
                                                                :static_cast<std::size_t>(system_vector.size())
                                                                -static_cast<std::size_t>(1));
        system_vector.emplace(system_vector.begin()
                              +static_cast<std::vector<std::uintmax_t>::difference_type>(distribution(engine)),
                              std::numeric_limits<std::uintmax_t>::max());
    }

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Emplacement for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Emplacing tree_vector<std::uintmax_t>()...\n";
    tree_vector<std::uintmax_t> system_tree_vector;

    start_time_point=std::chrono::steady_clock::now();

    for(std::uintmax_t index{};
        index<source_value_count;
        ++index)
    {
        distribution=std::uniform_int_distribution<std::size_t>(std::size_t(),
                                                                system_tree_vector.empty()
                                                                ?std::size_t()
                                                                :static_cast<std::size_t>(system_tree_vector.size())
                                                                -static_cast<std::size_t>(1));
        system_tree_vector.emplace(distribution(engine),
                                   std::numeric_limits<std::uintmax_t>::max());
    }

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Emplacement for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void pop_back_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting pop back benchmark...\n";

    std::cout<<"Constructing std::vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    std::vector<std::uintmax_t> system_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));

    std::cout<<"Popping back std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    for(std::uintmax_t index{};
        index<source_value_count;
        ++index)
    {
        system_vector.pop_back();
    }

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Pop back for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Constructing tree_vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    tree_vector<std::uintmax_t> system_tree_vector(static_cast<std::size_t>(source_value_count));

    std::cout<<"Popping back tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    for(std::uintmax_t index{};
        index<source_value_count;
        ++index)
    {
        system_tree_vector.pop_back();
    }

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Pop back for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void erase_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting erase benchmark...\n";

    std::random_device device;
    std::default_random_engine engine(device());
    std::uniform_int_distribution<std::size_t> distribution;

    std::cout<<"Constructing std::vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    std::vector<std::uintmax_t> system_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));

    std::cout<<"Erasing std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    for(std::uintmax_t index{};
        index<source_value_count;
        ++index)
    {
        distribution=std::uniform_int_distribution<std::size_t>(std::size_t(),
                                                                system_vector.empty()
                                                                ?std::size_t()
                                                                :static_cast<std::size_t>(system_vector.size())
                                                                -static_cast<std::size_t>(1));
        system_vector.erase(system_vector.begin()
                            +static_cast<std::vector<std::uintmax_t>::difference_type>(distribution(engine)));
    }

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Erasure for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Constructing tree_vector<std::uintmax_t>() with "
             <<source_value_count
             <<" value(s)...\n";
    tree_vector<std::uintmax_t> system_tree_vector(static_cast<std::size_t>(source_value_count));

    std::cout<<"Erasing tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    for(std::uintmax_t index{};
        index<source_value_count;
        ++index)
    {
        distribution=std::uniform_int_distribution<std::size_t>(std::size_t(),
                                                                system_tree_vector.empty()
                                                                ?std::size_t()
                                                                :static_cast<std::size_t>(system_tree_vector.size())
                                                                -static_cast<std::size_t>(1));
        system_tree_vector.erase(distribution(engine));
    }

    end_time_point=std::chrono::steady_clock::now();
    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Erasure for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void less_comparison_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting less comparison benchmark...\n";

    std::cout<<"Constructing std::vector<std::uintmax_t>()s with "
             <<source_value_count
             <<" value(s)...\n";
    const std::vector<std::uintmax_t> source_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));
    const std::vector<std::uintmax_t> system_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));

    std::cout<<"Less comparing std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    bool less(source_vector<system_vector);

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    if(less)
    {
        std::cerr<<"Less comparison failed for std::vector<std::uintmax_t>()\n";
    }

    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Less comparison for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Constructing tree_vector<std::uintmax_t>()s with "
             <<source_value_count
             <<" value(s)...\n";
    const tree_vector<std::uintmax_t> source_tree_vector(static_cast<std::size_t>(source_value_count));
    const tree_vector<std::uintmax_t> system_tree_vector(static_cast<std::size_t>(source_value_count));

    std::cout<<"Less comparing tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    less=(source_tree_vector<system_tree_vector);

    end_time_point=std::chrono::steady_clock::now();
    if(less)
    {
        std::cerr<<"Less comparison failed for tree_vector<std::uintmax_t>()\n";
    }

    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Less comparison for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void greater_comparison_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting greater comparison benchmark...\n";

    std::cout<<"Constructing std::vector<std::uintmax_t>()s with "
             <<source_value_count
             <<" value(s)...\n";
    const std::vector<std::uintmax_t> source_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));
    const std::vector<std::uintmax_t> system_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));

    std::cout<<"Greater comparing std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    bool greater(source_vector>system_vector);

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    if(greater)
    {
        std::cerr<<"Greater comparison failed for std::vector<std::uintmax_t>()\n";
    }

    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Greater comparison for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Constructing tree_vector<std::uintmax_t>()s with "
             <<source_value_count
             <<" value(s)...\n";
    const tree_vector<std::uintmax_t> source_tree_vector(static_cast<std::size_t>(source_value_count));
    const tree_vector<std::uintmax_t> system_tree_vector(static_cast<std::size_t>(source_value_count));

    std::cout<<"Greater comparing tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    greater=(source_tree_vector>system_tree_vector);

    end_time_point=std::chrono::steady_clock::now();
    if(greater)
    {
        std::cerr<<"Greater comparison failed for tree_vector<std::uintmax_t>()\n";
    }

    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Greater comparison for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void less_equal_comparison_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting less equal comparison benchmark...\n";

    std::cout<<"Constructing std::vector<std::uintmax_t>()s with "
             <<source_value_count
             <<" value(s)...\n";
    const std::vector<std::uintmax_t> source_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));
    const std::vector<std::uintmax_t> system_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));

    std::cout<<"Less equal comparing std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    bool less_equal(source_vector<=system_vector);

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    if(!less_equal)
    {
        std::cerr<<"Less equal comparison failed for std::vector<std::uintmax_t>()\n";
    }

    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Less equal comparison for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Constructing tree_vector<std::uintmax_t>()s with "
             <<source_value_count
             <<" value(s)...\n";
    const tree_vector<std::uintmax_t> source_tree_vector(static_cast<std::size_t>(source_value_count));
    const tree_vector<std::uintmax_t> system_tree_vector(static_cast<std::size_t>(source_value_count));

    std::cout<<"Less equal comparing tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    less_equal=(source_tree_vector<=system_tree_vector);

    end_time_point=std::chrono::steady_clock::now();
    if(!less_equal)
    {
        std::cerr<<"Less equal comparison failed for tree_vector<std::uintmax_t>()\n";
    }

    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Less equal comparison for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void greater_equal_comparison_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting greater equal comparison benchmark...\n";

    std::cout<<"Constructing std::vector<std::uintmax_t>()s with "
             <<source_value_count
             <<" value(s)...\n";
    const std::vector<std::uintmax_t> source_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));
    const std::vector<std::uintmax_t> system_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));

    std::cout<<"Greater equal comparing std::vector<std::uintmax_t>()...\n";

    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    bool greater_equal(source_vector>=system_vector);

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    if(!greater_equal)
    {
        std::cerr<<"Greater equal comparison failed for std::vector<std::uintmax_t>()\n";
    }

    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Greater equal comparison for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Constructing tree_vector<std::uintmax_t>()s with "
             <<source_value_count
             <<" value(s)...\n";
    const tree_vector<std::uintmax_t> source_tree_vector(static_cast<std::size_t>(source_value_count));
    const tree_vector<std::uintmax_t> system_tree_vector(static_cast<std::size_t>(source_value_count));

    std::cout<<"Greater equal comparing tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    greater_equal=(source_tree_vector>=system_tree_vector);

    end_time_point=std::chrono::steady_clock::now();
    if(!greater_equal)
    {
        std::cerr<<"Greater equal than comparison failed for tree_vector<std::uintmax_t>()\n";
    }

    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Greater equal comparison for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void equal_comparison_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting equal comparison benchmark...\n";

    std::cout<<"Constructing std::vector<std::uintmax_t>()s with "
             <<source_value_count
             <<" value(s)...\n";
    const std::vector<std::uintmax_t> source_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));
    const std::vector<std::uintmax_t> system_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));

    std::cout<<"Equal comparing std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    bool equal(source_vector==system_vector);

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    if(!equal)
    {
        std::cerr<<"Equal comparison failed for std::vector<std::uintmax_t>()\n";
    }

    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Equal comparison for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Constructing tree_vector<std::uintmax_t>()s with "
             <<source_value_count
             <<" value(s)...\n";
    const tree_vector<std::uintmax_t> source_tree_vector(static_cast<std::size_t>(source_value_count));
    const tree_vector<std::uintmax_t> system_tree_vector(static_cast<std::size_t>(source_value_count));

    std::cout<<"Equal comparing tree_vector<std::uintmax_t>()...\n";

    start_time_point=std::chrono::steady_clock::now();

    equal=(source_tree_vector==system_tree_vector);

    end_time_point=std::chrono::steady_clock::now();
    if(!equal)
    {
        std::cerr<<"Equal comparison failed for tree_vector<std::uintmax_t>()\n";
    }

    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Equal comparison for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

void not_equal_comparison_benchmark(const std::uintmax_t source_value_count)
{
    std::cout<<"Starting not equal comparison benchmark...\n";

    std::cout<<"Constructing std::vector<std::uintmax_t>()s with "
             <<source_value_count
             <<" value(s)...\n";
    const std::vector<std::uintmax_t> source_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));
    const std::vector<std::uintmax_t> system_vector(static_cast<std::vector<std::uintmax_t>::value_type>(source_value_count));

    std::cout<<"Not equal comparing std::vector<std::uintmax_t>()...\n";
    std::chrono::steady_clock::time_point start_time_point(std::chrono::steady_clock::now());

    bool not_equal(source_vector!=system_vector);

    std::chrono::steady_clock::time_point end_time_point(std::chrono::steady_clock::now());
    if(not_equal)
    {
        std::cerr<<"Not equal comparison failed for std::vector<std::uintmax_t>()\n";
    }

    std::chrono::seconds time_duration(std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                                        -start_time_point));
    std::cout<<"Not equal comparison for std::vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";

    std::cout<<"Constructing tree_vector<std::uintmax_t>()s with "
             <<source_value_count
             <<" value(s)...\n";
    const tree_vector<std::uintmax_t> source_tree_vector(static_cast<std::size_t>(source_value_count));
    const tree_vector<std::uintmax_t> system_tree_vector(static_cast<std::size_t>(source_value_count));

    std::cout<<"Not equal comparing tree_vector<std::uintmax_t>()...\n";
    start_time_point=std::chrono::steady_clock::now();

    not_equal=(source_tree_vector!=system_tree_vector);

    end_time_point=std::chrono::steady_clock::now();
    if(not_equal)
    {
        std::cerr<<"Not equal comparison failed for tree_vector<std::uintmax_t>()\n";
    }

    time_duration=std::chrono::duration_cast<std::chrono::seconds>(end_time_point
                                                                   -start_time_point);
    std::cout<<"Not equal comparison for tree_vector<std::uintmax_t>() took "
             <<time_duration.count()
             <<" second(s)\n";
}

int main()
{
    std::cout<<"Tree Vector benchmark program\n\n";

    bool value_count_input{};
    std::uintmax_t value_count{};
    while(!value_count_input)
    {
        std::cout<<"Enter value count for testing...\n\n";
        std::cin>>value_count;
        if(!std::cin)
        {
            std::cerr<<"\nError: value count entered must be an integer.\n";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                            '\n');
        }

        else
        {
            std::cout<<"\nEntered value count: "
                     <<value_count
                     <<"\n\n";
            value_count_input=true;
        }
    }

    default_construtor_benchmark();
    std::cout<<'\n';

    copy_constructor_benchmark(value_count);
    std::cout<<'\n';

    move_constructor_benchmark(value_count);
    std::cout<<'\n';

    value_count_constructor_benchmark(value_count);
    std::cout<<'\n';

    iterator_constructor_benchmark(value_count);
    std::cout<<'\n';

    initializer_list_constructor_benchmark();
    std::cout<<'\n';

    copy_assignment_benchmark(value_count);
    std::cout<<'\n';

    move_assignment_benchmark(value_count);
    std::cout<<'\n';

    initializer_list_assignment_benchmark();
    std::cout<<'\n';

    value_count_assignment_benchmark(value_count);
    std::cout<<'\n';

    iterator_assignment_benchmark(value_count);
    std::cout<<'\n';

    bracket_find_benchmark(value_count);
    std::cout<<'\n';

    at_find_benchmark(value_count);
    std::cout<<'\n';

    iterator_traverse_benchmark(value_count);
    std::cout<<'\n';

    reverse_iterator_traverse_benchmark(value_count);
    std::cout<<'\n';

    push_back_benchmark(value_count);
    std::cout<<'\n';

    emplace_back_benchmark(value_count);
    std::cout<<'\n';

    insert_benchmark(value_count);
    std::cout<<'\n';

    emplace_benchmark(value_count);
    std::cout<<'\n';

    pop_back_benchmark(value_count);
    std::cout<<'\n';

    erase_benchmark(value_count);
    std::cout<<'\n';

    less_comparison_benchmark(value_count);
    std::cout<<'\n';

    greater_comparison_benchmark(value_count);
    std::cout<<'\n';

    less_equal_comparison_benchmark(value_count);
    std::cout<<'\n';

    greater_equal_comparison_benchmark(value_count);
    std::cout<<'\n';

    equal_comparison_benchmark(value_count);
    std::cout<<'\n';

    not_equal_comparison_benchmark(value_count);

    return EXIT_SUCCESS;
}
