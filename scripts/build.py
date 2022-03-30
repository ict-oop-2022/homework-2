t()


parser = argparse.ArgumentParser(description='Build')
parser.add_argument('--config', '-c', default='Debug', choi>
parser.add_argument('--drop-build', '-d', action='store_tru>

args = parser.parse_args()
config = args.config

cwd = get_cwd()
folder = cwd + '/cmake-build-' + config

if args.drop:
    call_with_output(['rm', '-rf', folder], 'Remove build f>
call_with_output(['mkdir', '-p', folder], 'Create build fol>
call_with_output(['cmake', '-DCMAKE_BUILD_TYPE=' + config, >
call_with_output(['cmake', '--build', folder], 'Build')




